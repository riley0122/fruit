#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <string>

#include "station.hpp"
#include "time.hpp"

class Connection {
private:
    size_t from;
    size_t to;

    Time depart_time;
    Time arrive_time;
public:
    Connection(size_t from_station_index, size_t to_station_index, Time deprature, Time arrival);
    
    size_t GetFrom();
    size_t GetTo();

    Time GetDepartureTime();
    Time GetArrivalTime();
    Time GetDuration();
};

#endif /* CONNECTION_HPP */
