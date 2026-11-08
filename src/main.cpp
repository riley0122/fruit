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

    std::cout << graph.GetStationIndex("stoparea:17990") << std::endl; // Ermelo
    std::cout << graph.GetStationIndex("stoparea:18188") << std::endl; // Amsterdam Centraal
    std::cout << graph.GetStationIndex("stoparea:18000") << std::endl; // Zwolle

    // Amsterdam C
    std::cout << graph.GetStationIndex("2992168") << std::endl; // sppor 1
    std::cout << graph.GetStationIndex("2992171") << std::endl; // spoor 10b
    std::cout << graph.GetStationIndex("2992198") << std::endl; // spoor 8b

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
