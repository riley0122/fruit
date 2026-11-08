#ifndef GTFS_STOP_HPP
#define GTFS_STOP_HPP

#include <string>
#include <vector>

class GTFS_Stop {
private:
    std::string id;
    std::string code;
    std::string name;
    std::string lat;
    std::string lon;
    std::string location_type;
    std::string parent_station;
    std::string timezone;
    std::string wheelchair_boarding;
    std::string platform_code;
    std::string zone_id;
    std::string ifopt;
public:
    GTFS_Stop(std::vector<std::string> stop_data);

    std::string GetId();
    std::string GetCode();
    std::string GetName();
    std::string GetLat();
    std::string GetLon();
    std::string GetLocationType();
    std::string GetParentStation();
    std::string GetTimezone();
    std::string GetWheelchairBoarding();
    std::string GetPlatformCode();
    std::string GetZoneId();
    std::string GetIfopt();
};

#endif