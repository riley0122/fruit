#include <iostream>
#include "config.hpp"
#include "gtfs.hpp"
#include "graph.hpp"

Config* initialize_config();
GTFS* initialize_gtfs(Config* config);

void run_plan(Config* config);

int main(int argc, char *argv[]) {
    Config* config = initialize_config();
    if (!config->GetIsValid()) {
        std::cout << "Invalid config file!" << std::endl;
        return 1;
    }

    GTFS* gtfs = initialize_gtfs(config);

    Graph graph(*gtfs);

    delete gtfs;

    std::cout << graph.GetStationIndex("stoparea:17990") << std::endl;
    std::cout << graph.GetStationIndex("stoparea:18188") << std::endl;
    std::cout << graph.GetStationIndex("stoparea:18000") << std::endl;

    return 0;
}

Config* initialize_config() {
    Config* config = new Config("config.cfg");
    config->Read();
    return config;
}

GTFS* initialize_gtfs(Config* config) {
    GTFS* gtfs = new GTFS(config->GetGTFSFolderPath());
    gtfs->Read();
    return gtfs;
}
