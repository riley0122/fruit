#ifndef GTFS_SHAPE_HPP
#define GTFS_SHAPE_HPP

#include <string>
#include <vector>

class GTFS_Shape {
private:
    std::string id;
    std::string pt_sequence;
    std::string pt_lat;
    std::string pt_lon;
    std::string dist_traveled;
public:
    GTFS_Shape(std::vector<std::string> shape_data);

    std::string GetId();
    std::string GetPtSequence();
    std::string GetPtLat();
    std::string GetPtLon();
    std::string GetDistTraveled();
};

#endif /* GTFS_SHAPE_HPP */