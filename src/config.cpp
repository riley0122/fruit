#include "config.hpp"

Config::Config(std::string file_path) {
    this->file_path = file_path;
}

std::string Config::GetApiKey() {
    return this->api_key;
}
