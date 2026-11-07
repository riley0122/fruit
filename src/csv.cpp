#include "csv.hpp"

std::vector<std::string> split(std::string input_str, char splitter) {
    const char* input = input_str.c_str();
    std::vector<std::string> parts;

    std::string current;
    
    for (uint8_t i = 0; i < strlen(input); i++) {
        char current_char = input[i];

        if (current_char == splitter) {
            parts.push_back(current);
            current = "";
        } else {
            current.push_back(current_char);
        }
    }

    parts.push_back(current);

    return parts;
}

CSV::CSV(std::string file_path) {
    this->FileStream = std::ifstream(file_path);

    std::string line;
    std::getline(this->FileStream, line);
    this->column_names = split(line, ',');
}

std::vector<std::string> CSV::ReadNextRow() {
    std::string line;
    std::getline(this->FileStream, line);
    return split(line, ',');
}

bool CSV::HasNextRow() {
    return this->FileStream.peek() != EOF;
}

CSV::~CSV() {
    this->FileStream.close();
}