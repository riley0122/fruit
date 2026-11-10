#include "connection.hpp"

Connection::Connection(size_t from, size_t to, Time deprature, Time arrival) {
    this->from = from;
    this->to = to;
    this->depart_time = deprature;
    this->arrive_time = arrival;

#ifdef DEBUG
    std::cout << "New connection from " << from << " to " << to << " at " << deprature.GetReadable() << " taking " << (arrival - deprature).GetReadable() << std::endl;
#endif
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

void Connection::save(std::ofstream* output, Station from_station, Station to_station){
    // Save foramt:
    // [from station id size 4 bytes][from station id][to station id size 4 bytes][to station id][departure time 4 bytes timestamp][arrival time 4 bytes timestamp]
    std::string from_id = from_station.GetId();
    uint32_t from_id_length = from_id.length();
    output->write(reinterpret_cast<const char*>(&from_id_length), sizeof(from_id_length));
    output->write(from_id.data(), from_id_length);

    std::string to_id = to_station.GetId();
    uint32_t to_id_length = from_id.length();
    output->write(reinterpret_cast<const char*>(&to_id_length), sizeof(to_id_length));
    output->write(to_id.data(), to_id_length);

    uint32_t departure_timestamp = this->depart_time.GetTimestamp();
    output->write(reinterpret_cast<const char*>(&departure_timestamp), sizeof(departure_timestamp));

    uint32_t arrival_timestamp = this->depart_time.GetTimestamp();
    output->write(reinterpret_cast<const char*>(&arrival_timestamp), sizeof(arrival_timestamp));
}

