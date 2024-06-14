#include"Include/exception.h"

void log(std::string log) {
    std::cout << "[o] Log: " << log << std::endl;
}

void response(std::string response) {
    std::cout << "{} Client Response: " << response << std::endl;
}

void exception(std::string exception) {
    std::cout << "[x] Exception: " << exception << std::endl << "  Error Code: " << errno << std::endl;
}