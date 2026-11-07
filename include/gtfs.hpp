#ifndef GTFS_HPP
#define GTFS_HPP

#include <string>
#include "csv.hpp"

#include "gtfs_agency.hpp"
#include "gtfs_calendar_date.hpp"

class GTFS {
private:
    std::string directory;

    std::vector<GTFS_Agency> agencies;
    std::vector<GTFS_Calendar_Date> calendar_dates;

    template<class T>
    void ReadGeneric(std::string file_name, std::vector<T>* list);

    void ReadAgency();
    void ReadCalendarDate();
public:
    GTFS(std::string file_path);
    void Read();
};

#endif /* GTFS_HPP */