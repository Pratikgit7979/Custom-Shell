#ifndef SHELL_H
#define SHELL_H
#include <string>
#include <vector>
struct Job {
    int id;
    pid_t pid;
    std::string command;
    bool running;
};
#endif
