#include "gtfs.hpp"

GTFS::GTFS(std::string file_path) {
    if (file_path.ends_with("/")) {
        this->directory = file_path;
    } else {
        this->directory = file_path + "/";
    }
}

template<class T>
void GTFS::ReadGeneric(std::string file_name, std::vector<T>* list) {    
    CSV file = CSV(this->directory + file_name);

    while (file.HasNextRow()) {
        std::vector<std::string> data = file.ReadNextRow();
        T object = T(data);
        list->push_back(object);
    }
}

void GTFS::ReadAgency() {
    this->ReadGeneric<GTFS_Agency>("agency.txt", &this->agencies);
}

void GTFS::ReadCalendarDate() {
    this->ReadGeneric<GTFS_Calendar_Date>("calendar_dates.txt", &this->calendar_dates);
}

void GTFS::ReadRoute() {
    this->ReadGeneric<GTFS_Route>("routes.txt", &this->routes);
}

void GTFS::ReadShape() {
    this->ReadGeneric<GTFS_Shape>("shapes.txt", &this->shapes);
} 

void GTFS::ReadStopTime() {
    this->ReadGeneric<GTFS_Stop_time>("stop_times.txt", &this->stop_times);
}

void GTFS::Read() {
    std::cout << "Reading agencies..." << std::endl;
    this->ReadAgency();
    std::cout << "Reading calendar dates..." << std::endl;
    this->ReadCalendarDate();
    std::cout << "Reading routes..." << std::endl;
    this->ReadRoute();
    std::cout << "Reading shapes..." << std::endl;
    this->ReadShape();
    std::cout << "Reading stop times..." << std::endl;
    this->ReadStopTime();
}