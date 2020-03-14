#include "../../include/Allele.h"

RandomBinary::RandomBinary(int genSize)
: Allele(genSize, 0, 1) {
    this->generate();
}

void RandomBinary::generate(){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<> distr(0, 1);
    for (int i = 0; i < this->genSize; i++) {
        this->gen[i] = distr(generator);
    }
}
