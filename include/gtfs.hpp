#ifndef GTFS_HPP
#define GTFS_HPP

#include <string>
#include "csv.hpp"

class GTFS {
private:
    std::string directory;

    void ReadAgency();
public:
    GTFS(std::string file_path);
    void Read();
};

#endif /* GTFS_HPP */