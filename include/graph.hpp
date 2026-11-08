#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <algorithm>

#include "gtfs.hpp"
#include "gtfs_stop.hpp"
#include "station.hpp"
#include "connection.hpp"

class Graph {
private:
    std::vector<Station> stations;
    std::vector<Connection> connections;

    std::unordered_map<std::string, size_t> station_lookup;
public:
    Graph(GTFS gtfs_data);

    size_t GetStationIndex(std::string station_id);
    std::vector<std::string> SearchStation(std::string query);

    std::vector<Connection> GetRoute(Time start_time, std::vector<size_t>);
};

#endif /* GRAPH_H */
