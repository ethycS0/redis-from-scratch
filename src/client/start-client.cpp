#include"client.h"

int main() {
    Client client = Client("0.0.0.0", 1234);
    client.connectServer();
}