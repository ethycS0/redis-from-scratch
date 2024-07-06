#include"client.h"

int main(int argc, char **argv) {
    Client client = Client("0.0.0.0", 1234);
    int socket = client.connectServer();
    
    std::vector<std::string> cmd;
    
    for(int i = 1; i < argc; ++i) {
        cmd.push_back(argv[i]);
    }

    int32_t send_err = client.sendRequest(socket, cmd);
    if(send_err) {
        exception("Error Sending Message");
    }

    int32_t read_err = client.readResponse(socket);
    if(read_err) {
        client.closeClient();
    }

    client.closeClient();
}