#include "station.hpp"

Station::Station(GTFS_Stop original) {
#ifdef DEBUG
    std::cout << "New Station " << original.GetId() << ":" << original.GetName() << " at " << original.GetLat() << ", " << original.GetLon() << std::endl;
#endif
    float lat = std::stof(original.GetLat());
    float lon = std::stof(original.GetLon());
    Position pos(lat, lon);
    this->position = pos;

    this->id = original.GetId();
    this->name = original.GetName();
}

std::string Station::GetId() {
    return this->id;
}

std::string Station::GetName() {
    return this->name;
}

Position Station::GetPosition() {
    return this->position;
}

void Station::add_connection(size_t connection_index) {
    this->connection_indexes.push_back(connection_index);
}

std::vector<size_t> Station::getConnections() {
    return this->connection_indexes;
}
