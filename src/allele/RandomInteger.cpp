
class RandomInteger: public Allele<int>{
public:
    RandomInteger(int genSize, int lowerBound, int upperBound)
    :Allele(genSize, upperBound, lowerBound){
        this->generate();
    }
    void generate() override{
        std::random_device rand_dev;
        std::mt19937 generator(rand_dev());
        std::uniform_int_distribution<> distr(lowerBound, upperBound);
        for(int i=0; i<this->genSize; i++){
            this->gen[i] = distr(generator);
        }
    }

};
