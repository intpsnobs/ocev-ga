#ifndef FREADER_H
#define FREADER_H

#include <fstream>

class Freader {
private:
    std::fstream file;
public:
    void open(std::string fName);

    std::pair<std::string,std::string> readLine();

    bool hasContent();

};

#endif
