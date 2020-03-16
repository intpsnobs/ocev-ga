#ifndef FREADER_H
#define FREADER_H

#include <iostream>
#include <fstream>

class Freader {
private:
    std::fstream file;
public:
    bool open(std::string fName);

    std::pair<std::string,std::string> readLine();
    bool isOpen();
    bool hasContent();
    ~Freader() {
        file.close();
    }

};

#endif
