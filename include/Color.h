#include <iostream>
#include <string>

class Color {
private:
public:
    std::string setColor(int);

    ~Color() {
        std::cout << "\033[0;0m";
        std::cerr << "\033[0;0m";
    }

};