#include "../../include/Freader.h"
#include <iostream>
#include <algorithm>

void Freader::open(std::string fName) {
    try {
        this->file.open(fName, std::fstream::in | std::fstream::out);
    } catch(std::exception const& e) {
        std::cout << "Error on Freader_open " << e.what() << std::endl;
    }
}

std::pair<std::string,std::string> Freader::readLine() {
    if(file.is_open()) {
        std::string token;
        std::string value;
        std::string fullLine;
        std::getline(this->file, fullLine);
        std::size_t it = fullLine.find("=");
        if (it != std::string::npos) {
            token = fullLine.substr(0, it);
            value = fullLine.substr(++it, fullLine.size());
        } else {
            token = fullLine;
            value = fullLine;
        }
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
        return {token,value};
    } else {
        return {"",""};
    }
}

bool Freader::hasContent() {
    return !this->file.eof();
}
