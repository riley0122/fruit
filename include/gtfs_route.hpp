#ifndef GTFS_ROUTE_HPP
#define GTFS_ROUTE_HPP

#include <string>
#include <vector>

#ifdef DEBUG
#include <iostream>
#endif

class GTFS_Route {
private:
    std::string id;
    std::string agency_id;
    std::string short_name;
    std::string long_name;
    std::string desc;
    std::string type;
    std::string color;
    std::string text_color;
    std::string url;
public:
    GTFS_Route(std::vector<std::string> route_data);

    std::string GetId();
    std::string GetAgencyId();
    std::string GetShortName();
    std::string GetLongName();
    std::string GetDescription();
    std::string GetType();
    std::string GetColor();
    std::string GetTextColor();
    std::string GetUrl();
};

#endif /* GTFS_ROUTE_HPP */