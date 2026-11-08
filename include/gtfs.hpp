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
#include "gtfs_stop.hpp"
#include "gtfs_transfer.hpp"
#include "gtfs_trip.hpp"

class GTFS {
private:
    std::string directory;

    std::vector<GTFS_Agency> agencies;
    std::vector<GTFS_Calendar_Date> calendar_dates;
    std::vector<GTFS_Route> routes;
    std::vector<GTFS_Shape> shapes;
    std::vector<GTFS_Stop_time> stop_times;
    std::vector<GTFS_Stop> stops;
    std::vector<GTFS_Transfer> transfers;
    std::vector<GTFS_Trip> trips;

    template<class T>
    void ReadGeneric(std::string file_name, std::vector<T>* list);

    void ReadAgency();
    void ReadCalendarDate();
    void ReadRoute();
    void ReadShape();
    void ReadStopTime();
    void ReadStop();
    void ReadTransfer();
    void ReadTrip();
public:
    GTFS(std::string file_path);
    void Read();
};

#endif /* GTFS_HPP */