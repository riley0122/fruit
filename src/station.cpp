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

void Station::save(std::ofstream* output) {
    // Save format:
    // [id size 4 bytes][id][name length 4 bytes][name][lat 4 bytes][lon 4 bytes]

    uint32_t id_length = this->id.length();
    output->write(reinterpret_cast<const char*>(&id_length), sizeof(id_length));
    output->write(this->id.data(), id_length);

    uint32_t name_length = this->name.length();
    output->write(reinterpret_cast<const char*>(&name_length), sizeof(name_length));
    output->write(this->name.data(), name_length);

    float lat = position.GetLat();
    float lon = position.GetLon();

    output->write(reinterpret_cast<const char*>(&lat), sizeof(position.GetLat()));
    output->write(reinterpret_cast<const char*>(&lon), sizeof(position.GetLon()));
}
