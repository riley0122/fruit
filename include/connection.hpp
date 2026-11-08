#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <string>

#include "station.hpp"
#include "time.hpp"

class Connection {
private:
    Station* from;
    Station* to;

    Time depart_time;
    Time arrive_time;
public:
    Connection(Station* from, Station* to, Time deprature, Time arrival);
    
    Station* GetFrom();
    Station* GetTo();

    Time GetDepartureTime();
    Time GetArrivalTime();
    Time GetDuration();
};

#endif /* CONNECTION_HPP */
