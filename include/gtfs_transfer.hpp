#ifndef GTFS_TRANSFER_HPP
#define GTFS_TRANSFER_HPP

#include <string>
#include <vector>

// from_stop_id,to_stop_id,from_route_id,to_route_id,
// from_trip_id,to_trip_id,transfer_type,min_transfer_time
class GTFS_Transfer {
private:
    std::string from_stop_id;
    std::string to_stop_id;
    std::string from_route_id;
    std::string to_route_id;
    std::string from_trip_id;
    std::string to_trip_id;
    std::string transfer_type;
    std::string min_transfer_time;
public:
    GTFS_Transfer(std::vector<std::string> transfer_data);

    std::string GetFromStopId();
    std::string GetToStopId();
    std::string GetFromRouteId();
    std::string GetToRouteId();
    std::string GetFromTripId();
    std::string GetToTripId();
    std::string GetTransferType();
    std::string GetMinTransferTime();
};

#endif /* GTFS_TRANSFER_HPP */