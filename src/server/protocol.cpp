#include"protocol.h"

int Protocol::startConnections(int socket) {

    std::vector<connection *> con_vec;
    std::vector<struct pollfd> poll_args;
    
    while(true) {
        poll_args.clear();

        struct pollfd pfd = {socket, POLLIN, 0};
        poll_args.push_back(pfd);

        for(connection *conn : con_vec) {
            if(!conn) {
                continue;
            }
            struct pollfd pfd = {};
            pfd.fd = conn -> fd;
            pfd.events = (conn->state == STATE_REQ) ? POLLIN : POLLOUT;
            pfd.events = pfd.events | POLLERR;
            poll_args.push_back(pfd);
        }

        int rv = poll(poll_args.data(), (nfds_t)poll_args.size(), 1000);
        if(rv < 0) {
            exception("Poll Error");
        }

        for(size_t i = 1; i < poll_args.size(); ++i) {
            if(poll_args[i].revents){
                connection *conn = con_vec[poll_args[i].fd];
                if(!conn) {
                    exception("Pointer Error");
                }
                connectionState(conn);
                if(conn->state == STATE_END) {
                    con_vec[conn -> fd] = NULL;
                    (void)close(conn -> fd);
                    free(conn);
                } 
            }
        }

        if(poll_args[0].revents) {
            (void) acceptConnection(con_vec, socket);
        }
    }

    return 0;
}

void Protocol::putConnection(std::vector<connection *> &con_vec, struct connection *sock_con) {
    if(con_vec.size() <= (size_t)sock_con->fd) {
        con_vec.resize(sock_con->fd + 1);
    }
    con_vec[sock_con->fd] = sock_con;
}

int32_t Protocol::acceptConnection(std::vector<connection *> &con_vec, int socket) {
    struct sockaddr_in client_addr = {};
    socklen_t socklen = sizeof(client_addr);
    int c_socket = accept(socket, (struct sockaddr *) &client_addr, &socklen);
    if(c_socket < 0) {
        exception("Error Acception Connection");
        return -1;
    }

    socket_nb(c_socket);

    struct connection *a_con = (struct connection*)malloc(sizeof(struct connection));
    if(!a_con) {
        close(c_socket);
        return -1;
    }

    a_con->fd = c_socket;
    a_con->state = STATE_REQ;
    a_con->r_size = 0;
    a_con->w_size = 0;
    a_con->sent_size = 0;
    putConnection(con_vec, a_con);
    return 0;
}

void Protocol::connectionState(connection *conn) {
    if(conn->state == STATE_REQ) {
        requestState(conn);
    } else if(conn->state == STATE_RES) {
        responseState(conn);
    } else{
        assert(0);
    }
}

void Protocol::requestState(connection* con) {
    while(true) {
        assert(con->r_size < sizeof(con->r_buffer));
        ssize_t r_val = 0;
        do {
            size_t cap = sizeof(con->r_buffer) - con->r_size;
            r_val = read(con->fd, &con->r_buffer[con->r_size], cap);
        } while(r_val < 0 && errno == EINTR);

        if(r_val < 0 && errno == EAGAIN) {
            break;
        }
        if(r_val < 0 ) {
            exception("Read Error");
            con->state = STATE_END;
            break;
        }
        if(r_val == 0) {
            if(con->r_size > 0) {
                exception("Unexpected End of File");
            } else {
                log("---End Of File---");
            }
            con->state = STATE_END;
            break;
        }

        con->r_size += (size_t)r_val;
        assert(con->r_size <= sizeof(con->r_buffer));

        while(oneRequest(con)) {}

        if (con->state != STATE_REQ) {
                return;
            }
    }
}

bool Protocol::oneRequest(connection* con) {
    if (con->r_size < 0) {
        return false;
    }

    uint32_t len = 0;
    std::memcpy(&len, &con->r_buffer[0], 4);

    if(len > max_msg) {
        exception("Message too long");
        con->state = STATE_END;
        return false;
    }

    if(4 + len > con->r_size) {
        return false;
    }
    response(&con->r_buffer[4], agent);

    std::memcpy(&con->w_buffer[0], &len, 4);
    std::memcpy(&con->w_buffer[4], &con->r_buffer[4], len);
    con->w_size = 4 + len;

    size_t remain = con->r_size - 4 - len;
    if(remain) {
        memmove(con->r_buffer, &con->r_buffer[4 + len], remain);
    }
    con->r_size = remain;

    con->state=STATE_RES;
    responseState(con);

    return(con->state == STATE_REQ);
}

void Protocol::responseState(connection* con) {
    while(true) {
        ssize_t w_val = 0;
        do{
            size_t remain = con->w_size - con->sent_size;
            w_val = write(con->fd, &con->w_buffer[con->sent_size], remain);
        } while(w_val < 0 && errno == EINTR);

        if(w_val < 0 && errno == EAGAIN) {
            break;
        }

        if(w_val < 0) {
            exception("Write Error");
            con->state = STATE_END;
            break;
        }

        con->sent_size += (size_t)w_val;
        assert(con->sent_size <= con->w_size);
        if(con->sent_size == con->w_size) {
            con->state = STATE_REQ;
            con->sent_size = 0;
            con->w_size = 0;
            break;
        }
    }
}