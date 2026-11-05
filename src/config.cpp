#include "config.hpp"

Config::Config(std::string file_path) {
    this->file_path = file_path;
}

std::string Config::GetApiKey() {
    return this->api_key;
}

void Config::Read() {
    std::string line;
    std::ifstream ConfigFile(this->file_path);

    while (std::getline(ConfigFile, line)) {
        // Remove all spaces
        auto new_end = remove(line.begin(), line.end(), ' ');
        line.erase(new_end, line.end());

        if (line.starts_with("#")) {
            continue;
        } else if (line.starts_with("NS_API_KEY")) {
            this->api_key = line.substr(11);
        }
    }

    ConfigFile.close();
}
