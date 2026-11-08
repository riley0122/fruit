#include "gtfs_transfer.hpp"

GTFS_Transfer::GTFS_Transfer(std::vector<std::string> transfer_data) {
    // from_stop_id,to_stop_id,from_route_id,to_route_id,
    // from_trip_id,to_trip_id,transfer_type,min_transfer_time
    if (transfer_data.size() != 8) { return; }

    this->from_stop_id = transfer_data[0];
    this->to_stop_id = transfer_data[1];
    this->from_route_id = transfer_data[2];
    this->to_route_id = transfer_data[3];
    this->from_trip_id = transfer_data[4];
    this->to_trip_id = transfer_data[5];
    this->transfer_type = transfer_data[6];
    this->min_transfer_time = transfer_data[7];
}

std::string GTFS_Transfer::GetFromStopId() {
    return this->from_stop_id;
}

std::string GTFS_Transfer::GetToStopId() {
    return this->to_stop_id;
}

std::string GTFS_Transfer::GetFromRouteId() {
    return this->from_route_id;
}

std::string GTFS_Transfer::GetToRouteId() {
    return this->to_route_id;
}

std::string GTFS_Transfer::GetFromTripId() {
    return this->from_trip_id;
}

std::string GTFS_Transfer::GetToTripId() {
    return this->to_trip_id;
}

std::string GTFS_Transfer::GetTransferType() {
    return this->transfer_type;
}

std::string GTFS_Transfer::GetMinTransferTime() {
    return this->min_transfer_time;
}
