class RandomBinary: public Allele<int>{
public:
    RandomBinary(int genSize)
    :Allele(genSize){
        this->generate();
    }
    void generate() override{
        std::random_device rand_dev;
        std::mt19937 generator(rand_dev());
        std::uniform_int_distribution<> distr(0, 1);
        for(int i=0; i<this->genSize; i++){
            this->gen[i] = distr(generator);;
        }
    }

};
