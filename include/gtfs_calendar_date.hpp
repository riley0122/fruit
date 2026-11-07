#ifndef GTFS_CALENDAR_DATE
#define GTFS_CALENDAR_DATE

#include <string>
#include <vector>
#include "csv.hpp"

class GTFS_Calendar_Date {
private:
    std::string id;
    std::string date;
    std::string exception_type;
public:
    GTFS_Calendar_Date(std::vector<std::string> calendar_date_data);
    std::string GetId();
    std::string GetName();
    std::string GetExceptionType();
};

#endif /* GTFS_CALENDAR_DATE */