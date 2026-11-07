#include "csv.hpp"

std::vector<std::string> split(std::string input, char splitter) {
    // TODO: implement
}

CSV::CSV(std::string file_path) {
    this->FileStream = std::ifstream(file_path);

    std::string line;
    std::getline(this->FileStream, line);

}

CSV::~CSV() {
    this->FileStream.close();
}