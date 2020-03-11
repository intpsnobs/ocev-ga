#include <bits/stdc++.h>

template <typename T>
class Individual {
    static_assert(std::is_same<T, int>::value 
                || std::is_same<T, double>::value, 
                "nao pode >:(");

private:
    T * chromosome;
    int size;
    T lowerBound;
    T upperBound;
    bool isPemutation;
public:
    Individual(int chromoSize, T lowerBound = 0, T upperBound = 1, bool isPemutation = false);
    void generate();
    T* getChromosome(){
        return this->chromosome;
    }
    int getSize(){
        return this->size;
    }
    T getUpperBound(){
        return this->upperBound;
    }
    friend std::ostream& operator<<(std::ostream& out, const Individual& ind){
        out << std::fixed << std::setprecision(2);
        out << "[";
        for(int i=0; i<ind.size; i++){
            out << ind.chromosome[i];
            if(i!=ind.size-1) out << ",";
        }
        out << "]";
        return out;
    }
};                                                                  

template <typename T>
Individual<T>::Individual(int chromoSize, T lowerBound , T upperBound, bool isPermutation) {
    this->chromosome = new T[chromoSize];
    this->size = chromoSize;
    this->lowerBound = lowerBound;
    this->upperBound = upperBound;
    this->isPemutation = isPemutation;
    this->generate();
}

template <> 
void Individual<int>::generate(){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<> distr(this->lowerBound, this->upperBound);
    for(int i=0; i<this->size; i++){
        this->chromosome[i] = distr(generator);
    }
}

template <> 
void Individual<double>::generate(){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<> distr(this->lowerBound, this->upperBound);
    for(int i=0; i<this->size; i++){
        this->chromosome[i] = distr(generator);;
    }
}