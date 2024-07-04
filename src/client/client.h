#ifndef INCLUDED_CLIENT
#define INCLUDED_CLIENT

#include<sys/socket.h>
#include<string>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstring>

class Client {

public:
    Client(std::string ip_address, int port);
    ~Client();
    void connectServer();
private:
    static const size_t max_msg = 4096;
    std::string agent = "Server";

    int m_port;
    std::string m_ipaddress;

    int m_socket;
    struct sockaddr_in m_sockaddr;
    ssize_t sockaddr_len;

    int startClient();
    void closeClient();

    int32_t sendRequest(int socket,const char *text);
    int32_t readResponse(int socket);

    // int32_t m_query(int socket, const char *text);

};

#endif
