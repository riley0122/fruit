#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <string>

#ifdef DEBUG
#include <iostream>
#endif

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

    void save(std::ofstream* output, Station from_station, Station to_station);
};

#endif /* CONNECTION_HPP */
