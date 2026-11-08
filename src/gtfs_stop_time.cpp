#include "gtfs_stop_time.hpp"

GTFS_Stop_time::GTFS_Stop_time(std::vector<std::string> stop_time_data) {
    // trip_id,stop_sequence,stop_id,stop_headsign,arrival_time,departure_time,pickup_type,drop_off_type,
    // timepoint,shape_dist_traveled,fare_units_traveled
    if (stop_time_data.size() != 11) { return; }
    this->trip_id = stop_time_data[0];
    this->stop_sequence = stop_time_data[1];
    this->stop_id = stop_time_data[2];
    this->stop_headsign = stop_time_data[3];
    this->arrival_time = stop_time_data[4];
    this->departure_time = stop_time_data[5];
    this->pickup_type = stop_time_data[6];
    this->drop_off_type = stop_time_data[7];
    this->timepoint = stop_time_data[8];
    this->shape_dist_traveled = stop_time_data[9];
    this->fare_units_traveled = stop_time_data[10];
}

std::string GTFS_Stop_time::GetTripId() {
    return this->trip_id;
}

std::string GTFS_Stop_time::GetStopSequence() {
    return this->stop_sequence;
}

std::string GTFS_Stop_time::GetStopId() {
    return this->stop_id;
}

std::string GTFS_Stop_time::GetStopHeadsign() {
    return this->stop_headsign;
}

std::string GTFS_Stop_time::GetArrivalTime() {
    return this->arrival_time;
}

std::string GTFS_Stop_time::GetDepartureTime() {
    return this->departure_time;
}

std::string GTFS_Stop_time::GetPickupType() {
    return this->pickup_type;
}

std::string GTFS_Stop_time::GetDropOffType() {
    return this->drop_off_type;
}

std::string GTFS_Stop_time::GetTimepoint() {
    return this->timepoint;
}

std::string GTFS_Stop_time::GetShapeDistTraveled() {
    return this->shape_dist_traveled;
}

std::string GTFS_Stop_time::GetFareUnitsTraveled() {
    return this->fare_units_traveled;
}
