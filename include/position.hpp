#ifndef POSITION_HPP
#define POSITION_HPP

class Position {
private:
    float lat;
    float lon;
public:
    Position() : lat(0), lon(0) {}
    Position(float lat, float lon) : lat(lat), lon(lon) {}

    float GetLat() {return this->lat;}
    float GetLon() {return this->lon;}
};

#endif /* POSITION_HPP */
