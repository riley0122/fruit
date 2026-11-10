#include <iostream>
#include "config.hpp"
#include "gtfs.hpp"
#include "graph.hpp"
#include "connection.hpp"

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
    graph.Save();

    size_t ermelo = graph.GetStationIndex("stoparea:17990");
    size_t hrwijk = graph.GetStationIndex("stoparea:18116");
    size_t adam_c = graph.GetStationIndex("stoparea:18188");
    size_t zwolle = graph.GetStationIndex("stoparea:18000");

    std::cout << ermelo << std::endl; // Ermelo
    std::cout << hrwijk << std::endl; // Harderwijk
    std::cout << adam_c << std::endl; // Amsterdam Centraal
    std::cout << zwolle << std::endl; // Zwolle


    // Amsterdam C
    std::cout << graph.GetStationIndex("2992168") << std::endl; // sppor 1
    std::cout << graph.GetStationIndex("2992171") << std::endl; // spoor 10b
    std::cout << graph.GetStationIndex("2992198") << std::endl; // spoor 8b

    Time start("12:00:00");
    
    std::vector<Connection> route_1 = graph.GetRoute(start, {hrwijk, ermelo});
    std::cout << route_1.size() << std::endl; // should be 1

    std::vector<Connection> route_2 = graph.GetRoute(start, {ermelo, hrwijk});
    std::cout << route_2.size() << std::endl; // should be 1

    std::vector<Connection> route_3 = graph.GetRoute(start, {zwolle, adam_c});
    std::cout << route_3.size() << std::endl; // should be 0, no direct route

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
