#ifndef POSITION_HPP
#define POSITION_HPP

class Position {
private:
    float lat;
    float lon;
public:
    Position(float lat, float lon) : lat(lat), lon(lon) {}

    float GetLat() {return this->lat;}
    float GetLon() {return this->lon;}
};

#endif /* POSITION_HPP */
