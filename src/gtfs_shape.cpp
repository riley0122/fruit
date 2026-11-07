#include "gtfs_shape.hpp"

GTFS_Shape::GTFS_Shape(std::vector<std::string> shape_data) {
    // shape_id,shape_pt_sequence,shape_pt_lat,shape_pt_lon,shape_dist_traveled
    if (shape_data.size() != 5) { return; }
    this->id = shape_data[0];
    this->pt_sequence = shape_data[1];
    this->pt_lat = shape_data[2];
    this->pt_lon = shape_data[3];
    this->dist_traveled = shape_data[4];
}

std::string GTFS_Shape::GetId() {
    return this->id;
}

std::string GTFS_Shape::GetPtSequence() {
    return this->pt_sequence;
}

std::string GTFS_Shape::GetPtLat() {
    return this->pt_lat;
}

std::string GTFS_Shape::GetPtLon() {
    return this->pt_lon;
}

std::string GTFS_Shape::GetDistTraveled() {
    return this->dist_traveled;
}
