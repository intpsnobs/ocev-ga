#include "../../include/Allele.h"

RandomInteger::RandomInteger(int genSize, int lowerBound, int upperBound)
:Allele(genSize, lowerBound, upperBound){
    this->generate();
}
void RandomInteger::generate(){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(lowerBound, upperBound);
    for(int i=0; i<this->genSize; i++){
        this->gen[i] = distr(generator);
    }
}
