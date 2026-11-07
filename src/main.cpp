#include <iostream>
#include "config.hpp"
#include "gtfs.hpp"

Config* initialize_config();

int main() {
    Config* config = initialize_config();
    if (!config->GetIsValid()) {
        std::cout << "Invalid config file!" << std::endl;
        return 1;
    }

    GTFS gtfs = GTFS(config->GetGTFSFolderPath());
    gtfs.Read();
    return 0;
}

Config* initialize_config() {
    Config* config = new Config("config.cfg");
    config->Read();
    return config;
}
