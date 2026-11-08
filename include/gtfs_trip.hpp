#ifndef GTFS_TRIP_HPP
#define GTFS_TRIP_HPP

#include <string>
#include <vector>

class GTFS_Trip {
private:
    std::string route_id;
    std::string service_id;
    std::string id;
    std::string realtime_id;
    std::string headsign;
    std::string short_name;
    std::string long_name;
    std::string direction_id;
    std::string block_id;
    std::string shape_id;
    std::string wheelchair_accessible;
    std::string bikes_allowed;
public:
    GTFS_Trip(std::vector<std::string> trip_data);

    std::string GetRouteId();
    std::string GetServiceId();
    std::string GetId();
    std::string GetRealtimeId();
    std::string GetHeadsign();
    std::string GetShortName();
    std::string GetLongName();
    std::string GetDirectionId();
    std::string GetBlockId();
    std::string GetShapeId();
    std::string GetWheelchairAccessible();
    std::string GetBikesAllowed();
};

#endif /* GTFS_TRIP_HPP */