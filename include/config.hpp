#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <fstream>
#include <algorithm>

class Config {
private:
    std::string file_path;
    std::string gtfs_folder_path;
    bool use_graph_file = false;
public:
    Config(std::string file_path);
    void Read();

    std::string GetGTFSFolderPath();
    bool GetUseGraphFile();
    bool GetIsValid();
};

#endif /* CONFIG_H*/