#include"server.h"


Server::Server(std::string ip_address, int port) : 
    m_port(port),
    m_ipaddress(ip_address),
    m_socket(),
    m_newsocket(),
    sockaddr_len(sizeof(m_sockaddr)) {
    m_sockaddr.sin_family = AF_INET;
    m_sockaddr.sin_port = htons(m_port);
    m_sockaddr.sin_addr.s_addr = inet_addr(m_ipaddress.c_str());
    if (startServer() != 0) {
        exception("Failed to start Server");
    }
}

Server::~Server() {
    closeServer();
}

int32_t Server::startServer() {
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(m_socket < 0) {
        exception("Failed To Initialize Socket");
        return 1;
    }

    int val = 1;
    setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

    int r_bind = bind(m_socket, (sockaddr *) &m_sockaddr, sockaddr_len);
    if (r_bind < 0) {
        exception("Failed to bind socket");
        return 1;
    }

    log("Server Started...............");
    return 0;
}

void Server::closeServer() {
    close(m_socket);
    close(m_newsocket);
    exit(0);
}

void Server::startListening() {
    int r_list = listen(m_socket, SOMAXCONN);
    if(r_list != 0 ) {
        exception("Failed to start Listenening");
    }

    std::string s_list = "Started Listening on " + m_ipaddress + ":" + std::to_string(m_port);
    log(s_list);

    socket_nb(m_socket);

    protocol.startConnections(m_socket);
}




// void Server::m_connect(int &newsocket) {
//     while(true) {
//         log("Waiting For Connections.........");
//         struct sockaddr_in client_addr = {};
//         socklen_t addrlen = sizeof(client_addr);
//         newsocket = accept(m_socket, (sockaddr *) &client_addr, &addrlen);
//         if(newsocket<0) {
//             exception("Failed to accept connection");
//             continue;
//         }
//         else {
//             log("Connection Successfull");
//         }

//         while(true) {
//             int32_t connection;
//             connection = m_request(newsocket);
//             if(connection != 0) {
//                 break;
//             }
//         }

//         close(newsocket);
//     }
// }

// int32_t Server::m_request(int socket) {
//     char r_buffer[4 + max_msg + 1];
//     int32_t header = m_read(socket, r_buffer, 4);
//     if(header != 0) {
//         if(errno ==0) {
//             log("End of Connection");
//         } else {
//             exception("Failed to read Header");
//         }
//         return header;
//     }

//     uint32_t r_len = 0;
//     std::memcpy(&r_len, &r_buffer, 4);
//     if (r_len > max_msg) {
//         exception("Message Too Long");
//         return -1;
//     }

//     int32_t v_data = m_read(socket, &r_buffer[4], r_len);
//     if (v_data != 0) {
//         exception("Failed to read Data");
//         return v_data;
//     }

//     r_buffer[4 + r_len] = '\0';
//     response(&r_buffer[4], agent);
    
//     char v_reply[] = "World!";
//     char w_buffer[4 + sizeof(v_reply)];
    
//     uint32_t w_len = 0;
//     w_len = (uint32_t)strlen(v_reply);
    
//     std::memcpy(w_buffer, &w_len, 4);
//     std::memcpy(&w_buffer[4], v_reply, w_len);

//     return m_write(socket, w_buffer, 4 + w_len);
// }



