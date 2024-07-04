#ifndef INCLUDED_SERVER
#define INCLUDED_SERVER

#include<sys/socket.h>
#include<string>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstring>

#include"../common/helper.h"
#include"protocol.h"

class Server {

public:
    Server(std::string ip_address, int port);
    ~Server();
    void startListening();

private:
    // std::string agent = "Client";
    
    static const size_t max_msg = 4096;
    
    int m_port;
    std::string m_ipaddress;
    
    int m_socket;
    int m_newsocket;
    
    struct sockaddr_in m_sockaddr;
    ssize_t sockaddr_len;
    
    int32_t startServer();
    void closeServer();

    Protocol protocol;
    // void m_connect(int &newsocket);
    // int32_t m_request(int socket);

};

#endif