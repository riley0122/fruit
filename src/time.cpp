#include "time.hpp"

Time::Time(std::string time) {
    std::vector<std::string> parts = split(time, ':');

    // Format is always HH:MM:SS
    if (parts.size() != 3) {return;}
    uint8_t hours = std::stoi(parts[0]);
    uint8_t minutes = std::stoi(parts[1]);
    uint8_t seconds = std::stoi(parts[2]);

    this->seconds_past_midnight = (hours * 60 * 60) + (minutes * 60) + seconds;
}

uint32_t Time::GetTimestamp() {
    return this->seconds_past_midnight;
}

std::string Time::GetReadable() {
    uint32_t total = this->seconds_past_midnight;
    uint8_t hours = total / (60 * 60);
    total -= hours * 60 * 60;
    uint8_t minutes = total / 60;
    total -= minutes * 60;
    uint8_t seconds = total;

    return std::format("{}:{}:{}", hours, minutes, seconds);
}

Time Time::operator+(Time other) {
    return Time(this->seconds_past_midnight + other.GetTimestamp());
}

Time Time::operator-(Time other) {
    int64_t time = this->seconds_past_midnight - other.GetTimestamp();
    if (time < 0) {
        return Time(-1 * time);
    } else {
        return Time(time);
    }
}
