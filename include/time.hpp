#ifndef TIME_HPP
#define TIME_HPP

#include <string>
#include <stdint.h>
#include <vector>
#include "csv.hpp"

class Time {
private:
    uint32_t seconds_past_midnight;
public:
    Time() : seconds_past_midnight(0) {}
    Time(std::string time);
    std::string GetReadable();
    uint32_t GetTimestamp();
};

#endif /* TIME_HPP */