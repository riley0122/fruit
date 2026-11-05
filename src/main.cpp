#include <iostream>
#include "config.hpp"

Config* config;

void initialize_config();

int main() {
    initialize_config();

    std::cout << config->GetApiKey() << std::endl;
    return 0;
}

void initialize_config() {
    config = new Config("config.cfg");
    config->Read();
}