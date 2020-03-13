#include"../../include/Allele.h"

// template<typename  T>
// class Allele{
//     public:
//         int genSize;
//         T lowerBound;
//         T upperBound;
//         T * gen;
template<typename T>
Allele<T>::Allele(int genSize, T lowerBound, T upperBound){
    this->genSize = genSize;
    this->gen = new T[genSize];
    this->lowerBound = lowerBound;
    this->upperBound = upperBound;
};

//         virtual void generate() = 0;
// template<typename T>
// Allele<T>::operator<<(std::ostream& out, const Allele<T>& allele){
//     out << std::fixed << std::setprecision(2);
//     out << "[";
//     for(int i=0; i<allele.genSize; i++){
//         out << allele.gen[i];
//         if(i!=allele.genSize-1) out << ",";
// }
// out << "]";
// return out;
// }

// };
