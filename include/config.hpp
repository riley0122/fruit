#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <fstream>
#include <algorithm>

class Config {
private:
    std::string file_path;
    std::string api_key;
public:
    Config(std::string file_path);
    void Read();

    std::string GetApiKey();
    bool GetIsValid();
};

#endif /* CONFIG_H*/