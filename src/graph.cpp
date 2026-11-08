#include "graph.hpp"

Graph::Graph(GTFS gtfs_data) {
    std::vector<GTFS_Stop> gtfs_stops = gtfs_data.GetStops();
    for (size_t i = 0; i < gtfs_stops.size(); i++) {
        Station newStation(gtfs_stops.at(i));
        this->stations.push_back(newStation);
        this->station_lookup[newStation.GetId()] = i;
    }
}

size_t Graph::GetStationIndex(std::string station_id) {
    return this->station_lookup[station_id];
}

std::vector<Connection> Graph::GetRoute(std::vector<size_t>) {
    // TODO: find route
}