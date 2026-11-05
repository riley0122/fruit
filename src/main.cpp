#include <iostream>
#include "config.hpp"

Config* config;

void initialize_config();

int main() {
    initialize_config();
    if (!config->GetIsValid()) {
        std::cout << "Invalid config file!" << std::endl;
        return 1;
    }

    std::cout << config->GetApiKey() << std::endl;
    return 0;
}

void initialize_config() {
    config = new Config("config.cfg");
    config->Read();
}