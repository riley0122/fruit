#ifndef TIME_HPP
#define TIME_HPP

#include <string>
#include <stdint.h>
#include <vector>
#include <cstdlib>
#include "csv.hpp"

class Time {
private:
    uint32_t seconds_past_midnight;
public:
    Time() : seconds_past_midnight(0) {}
    Time(uint32_t timestamp) : seconds_past_midnight(timestamp) {}
    Time(std::string time);
    std::string GetReadable();
    uint32_t GetTimestamp();

    Time operator+(Time other);
    Time operator-(Time other);
};

#endif /* TIME_HPP */