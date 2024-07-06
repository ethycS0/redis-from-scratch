#include"helper.h"
#include<fcntl.h>

bool cmd_is(const std::string &word, const char *cmd) {
    return 0 == strcasecmp(word.c_str(), cmd);
}

void log(std::string log) {
    std::cout << "[o] Log: " << log << std::endl;
}

void response(char* response, std::string agent) {
    std::cout << "{} " << agent << " Response: " << response << std::endl;
}

void response(unsigned char * response, std::string agent) {
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

void socket_nb(int socket) {
    errno =0;
    int flags = fcntl(socket, F_GETFL, 0);
    if(errno) {
        exception("fcntl() error");
        return;
    }

    flags |= O_NONBLOCK;

    errno = 0;
    (void)fcntl(socket, F_SETFL, flags);
    if(errno) {
        exception("fcntl() error");
    }
}