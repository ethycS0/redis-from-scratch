#include"helper.h"

size_t max_msg = 4096;

void log(std::string log) {
    std::cout << "[o] Log: " << log << std::endl;
}

void response(char* response, std::string agent) {
    std::cout << "{} " << agent << " Response: " << response << std::endl;
}

void exception(std::string exception) {
    std::cout << "[x] Exception: " << exception << std::endl << "  Error Code: " << errno << std::endl;
}

int32_t m_read(int socket, char* buffer, size_t n) {
    while(n > 0) {
        ssize_t rval = read(socket, buffer, n);
        if (rval <= 0) {
            exception("Read Error");
            return -1;
        }

        assert((size_t)rval <= n);
        n -= (size_t)rval;
        buffer += rval;
    }
    return 0;
}

int32_t m_write(int socket, char *buffer, size_t n) {
    while(n > 0) {
        ssize_t wval = write(socket, buffer, n);
        if(wval <= 0) {
            exception("Write Error");
            return -1;
        }
        assert((size_t)wval <= n);
        n -= (size_t)wval;
        buffer += wval;
    }
    return 0;
}