#ifndef GTFS_AGENCY_HPP
#define GTFS_AGENCY_HPP

#include <string>
#include <vector>
#include "csv.hpp"

#ifdef DEBUG
#include <iostream>
#endif

class GTFS_Agency {
private:
    std::string id;
    std::string name;
    std::string url;
    std::string timezone;
    std::string phone;
public:
    GTFS_Agency(std::vector<std::string> agency_data);
    std::string GetId();
    std::string GetName();
    std::string GetUrl();
    std::string GetPhone();
};

#endif /* GTFS_AGENCY_HPP */