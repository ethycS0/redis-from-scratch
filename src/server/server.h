#ifndef INCLUDED_SERVER
#define INCLUDED_SERVER

#include<sys/socket.h>
#include<string>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstring>

class Server {

public:
    Server(std::string ip_address, int port);
    ~Server();
    void startListening();

private:
    std::string agent = "Client";
    
    int m_port;
    std::string m_ipaddress;
    
    int m_socket;
    int m_newsocket;
    
    struct sockaddr_in m_sockaddr;
    ssize_t sockaddr_len;
    
    int32_t startServer();
    void closeServer();
    void m_connect(int &newsocket);
    
    int32_t m_request(int socket);
};

#endif
