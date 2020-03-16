#include "../../include/Color.h"

std::string Color::setColor(int colorIndex) {
    return "\033[" + std::to_string(colorIndex) + "m";
}