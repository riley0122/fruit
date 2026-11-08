#include "gtfs_trip.hpp"

GTFS_Trip::GTFS_Trip(std::vector<std::string> trip_data) {
    // route_id,service_id,trip_id,realtime_trip_id,trip_headsign,
    // trip_short_name,trip_long_name,direction_id,block_id,shape_id,
    // wheelchair_accessible,bikes_allowed
    if (trip_data.size() != 12) { return; }

    this->route_id = trip_data[0];
    this->service_id = trip_data[1];
    this->id = trip_data[2];
    this->realtime_id = trip_data[3];
    this->headsign = trip_data[4];
    this->short_name = trip_data[5];
    this->long_name = trip_data[6];
    this->direction_id = trip_data[7];
    this->block_id = trip_data[8];
    this->shape_id = trip_data[9];
    this->wheelchair_accessible = trip_data[10];
    this->bikes_allowed = trip_data[11];
}

std::string GTFS_Trip::GetRouteId() {
    return this->route_id;
}

std::string GTFS_Trip::GetServiceId() {
    return this->service_id;
}

std::string GTFS_Trip::GetId() {
    return this->id;
}

std::string GTFS_Trip::GetRealtimeId() {
    return this->realtime_id;
}

std::string GTFS_Trip::GetHeadsign() {
    return this->headsign;
}

std::string GTFS_Trip::GetShortName() {
    return this->short_name;
}

std::string GTFS_Trip::GetLongName() {
    return this->long_name;
}

std::string GTFS_Trip::GetDirectionId() {
    return this->direction_id;
}

std::string GTFS_Trip::GetBlockId() {
    return this->block_id;
}

std::string GTFS_Trip::GetShapeId() {
    return this->shape_id;
}

std::string GTFS_Trip::GetWheelchairAccessible() {
    return this->wheelchair_accessible;
}

std::string GTFS_Trip::GetBikesAllowed() {
    return this->bikes_allowed;
}
