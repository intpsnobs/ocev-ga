#include "../../include/Validator.h"

template<>
bool Validator::isValid(std::string str) {
    return !str.empty();
}

bool Validator::isValid(int nmr) {
    return nmr >= 0;
}

bool Validator::isValid(double nmr) {
    return nmr >= 0.0f;
}

template<typename T>
bool Validator::isValid(T data) {
    return data >= 0;
}