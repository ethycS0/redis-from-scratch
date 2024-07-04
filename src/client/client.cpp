#include"client.h"
#include"../common/helper.h"

Client::Client(std::string ip_address, int port) :
    m_port(port),
    m_ipaddress(ip_address),
    m_socket(),
    sockaddr_len(sizeof(m_sockaddr)) {
        m_sockaddr.sin_family = AF_INET;
        m_sockaddr.sin_port = htons(m_port);
        m_sockaddr.sin_addr.s_addr = inet_addr(m_ipaddress.c_str());
    if(startClient() < 0) {
        exception("Failed to start Client");
    }
}

Client::~Client() {
    closeClient();
}

int Client::startClient() {
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(m_socket < 0) {
        exception("Failed To Initialize Socket");
        return 1;
    }
    log("Client Started......");
    return 0;
}

void Client::closeClient() {
    close(m_socket);
    exit(0);
}

void Client::connectServer() {
    int r_con = connect(m_socket,(sockaddr *) &m_sockaddr, sockaddr_len);
    if(r_con != 0) {
        exception("Failed to Connect to Server");
    }
    std::string s_con = "Connected to Server at " + m_ipaddress + ":" + std::to_string(m_port);
    log(s_con);

    const char* q1 = "I";
    const char* q2 = "Love";
    const char* q3 = "You";

    const char* query[3] = {q1 , q2, q3};
    for(size_t i = 0; i < 3; ++i) {
        int32_t err = sendRequest(m_socket, query[i]);
        if(err) {
            exception("Error Sending Message");
        }
    }

    for(size_t i = 0; i < 3; ++i) {
        int32_t err = readResponse(m_socket);
        if(err) {
            closeClient();
        }
    }

    closeClient();
}

int32_t Client::sendRequest(int socket,const char *text) {
    uint32_t len = (uint32_t)strlen(text);
    if(len > max_msg) {
        exception("Message Too Long");
        return -1;
    }

    char w_buffer[4 + max_msg];
    std::memcpy(w_buffer, &len, 4);
    std::memcpy(&w_buffer[4], text, len);
    return m_write(socket, w_buffer, 4 + len);
}

int32_t Client::readResponse(int socket) {
    char r_buffer[4 + max_msg + 1];
    errno = 0;
    int32_t err = m_read(socket, r_buffer, 4);
    if(err) {
        if(errno == 0) {
            exception("---End Of File---");
        } else {
            exception("Error Reading message");
        }
        return err;
    }

    uint32_t len = 0;
    std::memcpy(&len, r_buffer, 4);
    if(len > max_msg) {
        exception("Message Too long");
        return -1;
    }

    err = m_read(socket, &r_buffer[4], len);
    if(err) {
        exception("Error reading Message");
        return err;
    }

    r_buffer[4 + len] = '\0';
    response(&r_buffer[4], agent);
    return 0;
}

// int32_t Client::m_query(int socket, const char* text) {
//     uint32_t w_len = (uint32_t)strlen(text);
//     if(w_len > max_msg) {
//         exception("Message Too Long");
//         return errno;
//     }

//     char w_buffer[4 + max_msg];
//     std::memcpy(w_buffer, &w_len, 4);
//     std::memcpy(&w_buffer[4], text, w_len);
    
//     int32_t v_data = m_write(socket, w_buffer, 4 + w_len);
//     if(v_data != 0) {
//         exception("Failed to write data");
//         return v_data;
//     }

//     char r_buffer[4 + max_msg + 1];
//     int32_t header = m_read(socket, r_buffer, 4);
//     errno = 0;
//     if(header != 0) {
//         if(errno ==0) {
//             log("End of Connection");
//         } else {
//             exception("Failed to read Header");
//         }
//         return header;
//     }
//     uint32_t r_len = 0;
//     std::memcpy(&r_len, r_buffer, 4);
//     if(r_len > max_msg) {
//         exception("Message too long");
//         return -1;
//     }

//     int32_t r_data = m_read(socket, &r_buffer[4], r_len);
//     if (r_data != 0) {
//         exception("Failed to read Data");
//         return v_data;
//     }

//     r_buffer[4 + r_len] = '\0';
    
//     response(&r_buffer[4], agent);
//     return 0;
// }