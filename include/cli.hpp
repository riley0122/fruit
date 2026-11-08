#ifndef CLI_HPP
#define CLI_HPP

#include <string>
#include <vector>
#include <iostream>
#include "csv.hpp"

enum CLI_COMMAND {
    COMMAND_HELP,
    COMMAND_PLAN,
    COMMAND_INVALID,
};

class CLI {
private:
    bool isValid = true;

    enum CLI_COMMAND command;
    std::vector<std::string> args;
public:
    CLI(int argc, char* argv[]);

    bool GetIsValid();
    enum CLI_COMMAND GetCommand();

    void help();
    void usage(std::string exec);
};

#endif /* CLI_HPP */