#ifndef STATION_H
#define STATION_H

#include <string>

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
};

#endif /* STATION_H */
