#include "gtfs_calendar_date.hpp"

GTFS_Calendar_Date::GTFS_Calendar_Date(std::vector<std::string> calendar_date_data) {
    // service_id,date,exception_type
    if (calendar_date_data.size() != 3) { return; }
    this->id = calendar_date_data[0];
    this->date = calendar_date_data[1];
    this->exception_type = calendar_date_data[2];
}

std::string GTFS_Calendar_Date::GetId() {
    return this->id;
}

std::string GTFS_Calendar_Date::GetName() {
    return this->date;
}

std::string GTFS_Calendar_Date::GetExceptionType() {
    return this->exception_type;
}
