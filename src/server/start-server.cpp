#include"server.h"

int main() {
    Server server = Server("0.0.0.0", 1234);
    server.startListening();
}