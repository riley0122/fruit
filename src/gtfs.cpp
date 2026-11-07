#include "gtfs.hpp"

GTFS::GTFS(std::string file_path) {
    if (file_path.ends_with("/")) {
        this->directory = file_path;
    } else {
        this->directory = file_path + "/";
    }
}

void GTFS::ReadAgency() {
    CSV agency_file = CSV(this->directory + "agency.txt");
}

void GTFS::Read() {
    this->ReadAgency();
}