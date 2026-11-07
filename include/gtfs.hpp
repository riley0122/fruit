#ifndef GTFS_HPP
#define GTFS_HPP

#include <string>
#include "csv.hpp"

#include "gtfs_agency.hpp"

class GTFS {
private:
    std::string directory;

    std::vector<GTFS_Agency> agencies;

    void ReadAgency();
public:
    GTFS(std::string file_path);
    void Read();
};

#endif /* GTFS_HPP */