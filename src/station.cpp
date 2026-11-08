#include "station.hpp"

Station::Station(GTFS_Stop original) {
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
