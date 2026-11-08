#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include "gtfs.hpp"
#include "station.hpp"
#include "connection.hpp"

class Graph {
private:
    std::vector<Station> stations;
    std::vector<Connection> connections;
public:
    Graph(GTFS gtfs_data);

    Station* GetStation(std::string station_id);
    std::vector<std::string> SearchStation(std::string query);

    std::vector<Connection> GetRoute(std::vector<Station*>);
};

#endif /* GRAPH_H */
