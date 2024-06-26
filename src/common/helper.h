#ifndef MAIN_HELPER
#define MAIN_HELPER

#include<iostream>
#include<string>
#include<unistd.h>
#include<assert.h>

void log(std::string log);
void response(char* response, std::string agent);
void exception(std::string exception);
    
int32_t m_read(int socket, char *buffer, size_t n);
int32_t m_write(int socket, char *buffer, size_t n);

extern size_t max_msg;

#endif