#ifndef COLOR_H
#define COLOR_H
#include <iostream>
#include <string>

#define DEF 0   // Reset
#define ERR 41  // Red bg
#define LOG 42  // Green bg
#define WAR 43  // Yellow bg

class Color {
private:
public:
    std::string setColor(int);

    ~Color() {
        std::cout << "\033[0;0m";
        std::cerr << "\033[0;0m";
    }

};
#endif