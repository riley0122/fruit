#ifndef STATION_H
#define STATION_H

#include <string>
#include <fstream>
#ifdef DEBUG
#include <iostream>
#endif

#include "gtfs_stop.hpp"
#include "position.hpp"

class Station {
private:
    std::string id;
    std::string name;

    std::vector<size_t> connection_indexes;

    Position position;
public:
    Station();
    Station(GTFS_Stop original);
    Station(std::string name, std::string id, Position position);

    std::string GetId();
    std::string GetName();
    Position GetPosition();
    
    void add_connection(size_t connection_index);
    std::vector<size_t> getConnections();

    void save(std::ofstream* output);
};

#endif /* STATION_H */
