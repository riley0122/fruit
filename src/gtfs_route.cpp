#include "gtfs_route.hpp"

GTFS_Route::GTFS_Route(std::vector<std::string> route_data) {
    // route_id,agency_id,route_short_name,route_long_name,route_desc,route_type,route_color,route_text_color,route_url
    if (route_data.size() != 9) { return; }
    this->id = route_data[0];
    this->agency_id = route_data[1];
    this->short_name = route_data[2];
    this->long_name = route_data[3];
    this->desc = route_data[4];
    this->type = route_data[5];
    this->color = route_data[6];
    this->text_color = route_data[7];
    this->url = route_data[8];

#ifdef DEBUG
    std::cout << "New route for " << this->agency_id << " with id " << this->id << std::endl;
#endif
}

std::string GTFS_Route::GetId() {
    return this->id;
}

std::string GTFS_Route::GetAgencyId() {
    return this->agency_id;
}

std::string GTFS_Route::GetShortName() {
    return this->short_name;
}

std::string GTFS_Route::GetLongName() {
    return this->long_name;
}

std::string GTFS_Route::GetDescription() {
    return this->desc;
}

std::string GTFS_Route::GetType() {
    return this->type;
}

std::string GTFS_Route::GetColor() {
    return this->color;
}

std::string GTFS_Route::GetTextColor() {
    return this->text_color;
}

std::string GTFS_Route::GetUrl() {
    return this->url;
}