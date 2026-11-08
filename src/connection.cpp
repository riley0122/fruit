#include "connection.hpp"

Connection::Connection(size_t from, size_t to, Time deprature, Time arrival) {
    this->from = from;
    this->to = to;
    this->depart_time = deprature;
    this->arrive_time = arrival;
}
    
size_t Connection::GetFrom() {
    return this->to;
}

size_t Connection::GetTo() {
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
