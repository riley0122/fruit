#ifndef STATION_H
#define STATION_H

#include <string>
#ifdef DEBUG
#include <iostream>
#endif

#include "gtfs_stop.hpp"
#include "position.hpp"

class Station {
private:
    std::string id;
    std::string name;

    Position position;
public:
    Station();
    Station(GTFS_Stop original);

    std::string GetId();
    std::string GetName();
    Position GetPosition();
};

#endif /* STATION_H */
