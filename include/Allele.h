#ifndef ALLELE_H
#define ALLELE_H

#include <ostream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>

template<typename  T>
class Allele{
    public:
        int genSize;
        T lowerBound;
        T upperBound;
        T * gen;

        Allele(int genSize, T lowerBound = 0, T upperBound = 1);

        virtual void generate() = 0;

        friend std::ostream& operator<<(std::ostream& out, const Allele<T>& allele);


};

class PermutedInteger: public Allele<int>{
public:
    PermutedInteger(int genSize, int lowerBound, int upperBound);
    void generate() override;
};

#endif