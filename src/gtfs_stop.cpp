#include "gtfs_stop.hpp"

GTFS_Stop::GTFS_Stop(std::vector<std::string> stop_data) {
    // stop_id,stop_code,stop_name,stop_lat,stop_lon,location_type,parent_station,
    // stop_timezone,wheelchair_boarding,platform_code,zone_id,stop_ifopt
    if (stop_data.size() != 12) { return; }
    this->id = stop_data[0];
    this->code = stop_data[1];
    this->name = stop_data[2];
    this->lat = stop_data[3];
    this->lon = stop_data[4];
    this->location_type = stop_data[5];
    this->parent_station = stop_data[6];
    this->timezone = stop_data[7];
    this->wheelchair_boarding = stop_data[8];
    this->platform_code = stop_data[9];
    this->zone_id = stop_data[10];
    this->ifopt = stop_data[11];
}

std::string GTFS_Stop::GetId() {
    return this->id;
}

std::string GTFS_Stop::GetCode() {
    return this->code;
}

std::string GTFS_Stop::GetName() {
    return this->name;
}

std::string GTFS_Stop::GetLat() {
    return this->lat;
}

std::string GTFS_Stop::GetLon() {
    return this->lon;
}

std::string GTFS_Stop::GetLocationType() {
    return this->location_type;
}

std::string GTFS_Stop::GetParentStation() {
    return this->parent_station;
}

std::string GTFS_Stop::GetTimezone() {
    return this->timezone;
}

std::string GTFS_Stop::GetWheelchairBoarding() {
    return this->wheelchair_boarding;
}

std::string GTFS_Stop::GetPlatformCode() {
    return this->platform_code;
}

std::string GTFS_Stop::GetZoneId() {
    return this->zone_id;
}

std::string GTFS_Stop::GetIfopt() {
    return this->ifopt;
}
