#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

class Validator {
private:
    Validator() {}
public:
    static bool isValid(std::string);
    static bool isValid(int);
    static bool isValid(double);
    template<typename T>
    static bool isValid(T);
};

#endif
