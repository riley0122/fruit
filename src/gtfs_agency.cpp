#include "gtfs_agency.hpp"

GTFS_Agency::GTFS_Agency(std::vector<std::string> agency_data) {
    // agency_id,agency_name,agency_url,agency_timezone,agency_phone
    if (agency_data.size() != 5) { return; }
    this->id = agency_data[0];
    this->name = agency_data[1];
    this->url = agency_data[2];
    this->timezone = agency_data[3];
    this->phone = agency_data[4];
}

std::string GTFS_Agency::GetId() {
    return this->id;
}

std::string GTFS_Agency::GetName() {
    return this->name;
}

std::string GTFS_Agency::GetUrl() {
    return this->url;
}

std::string GTFS_Agency::GetPhone() {
    return this->phone;
}
