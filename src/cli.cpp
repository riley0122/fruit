#include "cli.hpp"

CLI::CLI(int argc, char* argv[]) {
    if (argc < 2) {
        this->isValid = false;
        return;
    }

    std::string str_command = argv[1];

    if (str_command == "help") {
        this->command = COMMAND_HELP;
    } else if (str_command == "plan") {
        this->command = COMMAND_PLAN;
    } else {
        this->command = COMMAND_INVALID;
        this->isValid = false;
        return;
    }

    for (int i = 2; i < argc; i++) {
        this->args.push_back(argv[i]);
    }
}

bool CLI::GetIsValid() {
    return this->isValid;
}

enum CLI_COMMAND CLI::GetCommand() {
    return this->command;
}

void CLI::help() {
    std::cout << "Commands: help, plan." << std::endl;
    std::cout << "help: Shows this help menu" << std::endl;
    std::cout << "plan <min transfer time in minutes> <stop id's seperated by spaces>: plans the fastest possible trip through these stops in any order. Keeps the start and end." << std::endl;
} 

void CLI::usage(std::string exec) {
    std::cout << "usage: " << exec << " <command>" << std::endl;
    std::cout << "use the `help` command to get more info." << std::endl;
}
