#ifndef GTFS_HPP
#define GTFS_HPP

#include <string>
#include <iostream>

#include "csv.hpp"

#include "gtfs_agency.hpp"
#include "gtfs_calendar_date.hpp"
#include "gtfs_route.hpp"
#include "gtfs_shape.hpp"
#include "gtfs_stop_time.hpp"

class GTFS {
private:
    std::string directory;

    std::vector<GTFS_Agency> agencies;
    std::vector<GTFS_Calendar_Date> calendar_dates;
    std::vector<GTFS_Route> routes;
    std::vector<GTFS_Shape> shapes;
    std::vector<GTFS_Stop_time> stop_times;

    template<class T>
    void ReadGeneric(std::string file_name, std::vector<T>* list);

    void ReadAgency();
    void ReadCalendarDate();
    void ReadRoute();
    void ReadShape();
    void ReadStopTime();
public:
    GTFS(std::string file_path);
    void Read();
};

#endif /* GTFS_HPP */