#ifndef CONNECTION_PROTOCOL
#define CONNECTION_PROTOCOL

#include"../common/helper.h"
#include<sys/socket.h>
#include<string>
#include<unistd.h>
#include<stdint.h>
#include<vector>
#include<poll.h>
#include<netinet/in.h>
#include<cstring>
#include<map>

class Protocol {

public:
    int startConnections(int socket);

private:

    std::string agent = "Client";
    static const size_t max_args = 1024;


    static const size_t max_msg = 4096;

    struct connection {
        int fd = -1;
        uint32_t state = 0;
        size_t r_size = 0;
        uint8_t r_buffer[4 + max_msg];
        size_t w_size = 0;
        size_t sent_size = 0;
        uint8_t w_buffer[4 + 4096];
        
    };

    enum {
        STATE_REQ = 0,
        STATE_RES = 1,
        STATE_END = 2,
    };

    enum {
        RES_OK = 0,
        RES_ERR = 1,
        RES_NX = 2,
    };

    void putConnection(std::vector<connection *> &con_vec, struct connection *sock_con);
    int32_t acceptConnection(std::vector<connection *> &con_vec, int socket);
    void connectionState(connection *conn);

    void requestState(connection* con);
    void responseState(connection* con);

    bool oneRequest(connection *con);

    int32_t processRequest(uint8_t *req, uint32_t reqlen, uint32_t *rescode, uint8_t *res, uint32_t *reslen);
    int32_t parseRequest(uint8_t *data, size_t len, std::vector<std::string> &out);

    uint32_t cmdGET(std::vector<std::string> &cmd, uint8_t *res, uint32_t *reslen);
    uint32_t cmdSET(std::vector<std::string> &cmd, uint8_t *res, uint32_t *reslen);
    uint32_t cmdDEL(std::vector<std::string> &cmd, uint8_t *res, uint32_t *reslen);

    std::map<std::string, std::string> g_map;

};

#endif