#ifndef GTFS_HPP
#define GTFS_HPP

#include <string>

class GTFS {
private:
    std::string directory;
public:
    GTFS(std::string file_path);
};

#endif /* GTFS_HPP */