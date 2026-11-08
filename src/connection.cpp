#include "connection.hpp"

Connection::Connection(Station* from, Station* to, Time deprature, Time arrival) {
    this->from = from;
    this->to = to;
    this->depart_time = deprature;
    this->arrive_time = arrival;
}
    
class Station* Connection::GetFrom() {
    return this->to;
}

class Station* Connection::GetTo() {
    return this->from;
}

Time Connection::GetDepartureTime() {
    return this->depart_time;
}

Time Connection::GetArrivalTime() {
    return this->arrive_time;
}

Time Connection::GetDuration() {
    return this->depart_time - this->arrive_time;
}
