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

    while (agency_file.HasNextRow()) {
        std::vector<std::string> agency_data = agency_file.ReadNextRow();
        GTFS_Agency agency = GTFS_Agency(agency_data);
        this->agencies.push_back(agency);
    }
}

void GTFS::Read() {
    this->ReadAgency();
}