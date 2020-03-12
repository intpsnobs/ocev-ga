
class RandomDouble: public Allele<double>{
public:
    RandomDouble(int genSize, double lowerBound, double upperBound)
    :Allele(genSize, upperBound, lowerBound){
        this->generate();
    }
    void generate() override{
        std::random_device rand_dev;
        std::mt19937 generator(rand_dev());
        std::uniform_real_distribution<> distr(lowerBound, upperBound);
        for(int i=0; i<this->genSize; i++){
            this->gen[i] = distr(generator);;
        }
    }

};
