#include "../../include/Allele.h"



PermutedInteger::PermutedInteger(int genSize, int lowerBound, int upperBound)
:Allele(genSize, lowerBound, upperBound){
    this->generate();
}
void PermutedInteger::generate(){
    std::vector<int> sequence;

    for(int i = lowerBound; i<=upperBound; i++)
        sequence.push_back(i);

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::random_shuffle(sequence.begin(),sequence.end());
    std::copy(sequence.begin(), sequence.end(), gen);
}


