#include "config.hpp"

Config::Config(std::string file_path) {
    this->file_path = file_path;
}

std::string Config::GetGTFSFolderPath() {
    return this->gtfs_folder_path;
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
        } else if (line.starts_with("GTFS_FOLDER")) {
            this->gtfs_folder_path = line.substr(12);
        } else if (line.starts_with("USE_GRAPH_FILE")) {
            std::string input = line.substr(15);
            this->use_graph_file = input == "true";
        }
    }

    ConfigFile.close();
}

bool Config::GetIsValid() {
    return !(this->file_path == "" || this->gtfs_folder_path == "");
}

bool Config::GetUseGraphFile() {
    return this->use_graph_file;
}