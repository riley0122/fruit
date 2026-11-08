#ifndef GTFS_STOP_TIME_HPP
#define GTFS_STOP_TIME_HPP

#include <string>
#include <vector>

class GTFS_Stop_time {
private:
    std::string trip_id;
    std::string stop_sequence;
    std::string stop_id;
    std::string stop_headsign;
    std::string arrival_time;
    std::string departure_time;
    std::string pickup_type;
    std::string drop_off_type;
    std::string timepoint;
    std::string shape_dist_traveled;
    std::string fare_units_traveled;
public:
    GTFS_Stop_time(std::vector<std::string> stop_time_data);

    std::string GetTripId();
    std::string GetStopSequence();
    std::string GetStopId();
    std::string GetStopHeadsign();
    std::string GetArrivalTime();
    std::string GetDepartureTime();
    std::string GetPickupType();
    std::string GetDropOffType();
    std::string GetTimepoint();
    std::string GetShapeDistTraveled();
    std::string GetFareUnitsTraveled();
};

#endif /* GTFS_STOP_TIME_HPP */