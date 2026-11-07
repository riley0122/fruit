#ifndef CSV_HPP
#define CSV_HPP

#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> split(std::string input, char splitter);

class CSV {
private:
    uint8_t column_count;
    std::vector<std::string> column_names;

    std::ifstream FileStream;
public:
    CSV(std::string file_path);
    std::vector<std::string> ReadNextRow();
    ~CSV();
};

#endif /* CSV_HPP */