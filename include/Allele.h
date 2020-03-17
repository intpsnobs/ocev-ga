#ifndef ALLELE_H
#define ALLELE_H

#include <ostream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>

template<typename T>
class Allele {
    public:
        int genSize;
        T lowerBound;
        T upperBound;
        T * gen;

        Allele(int genSize, T lowerBound, T upperBound){
            this->genSize = genSize;
            this->gen = new T[genSize];
            this->lowerBound = lowerBound;
            this->upperBound = upperBound;
        };

        virtual void generate() = 0;

        friend std::ostream& operator<<(std::ostream& out, const Allele<T>& allele){
            out << std::fixed << std::setprecision(2);
            out << "[";
            for(int i=0; i<allele.genSize; i++){
                out << allele.gen[i];
                if(i!=allele.genSize-1) out << ",";
            }
            out << "]";
            return out;
        }
};

class PermutedInteger: public Allele<int>{
    public:
        PermutedInteger(int genSize, int lowerBound, int upperBound);
        void generate() override;
};

class RandomBinary: public Allele<int>{
    public:
        RandomBinary(int genSize);
        void generate() override;
};

class RandomInteger: public Allele<int>{
    public:
        RandomInteger(int genSize, int lowerBound, int upperBound);
        void generate() override;
};

class RandomDouble: public Allele<double>{
    public:
        RandomDouble(int genSize, double lowerBound, double upperBound);
        void generate() override;
};

#endif
