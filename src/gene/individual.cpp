template <typename T>
class Individual {
private:
    T * chromo;
    int size;
    static T lowerBound;
    static T upperBound;
public:
    Individual(int chromoSize, T lowerBound = 0, T upperBound = 1);
}

template<typename T>
Individual<T>::Individual(int chromoSize, T lowerBound, T upperBound) {
    this->chromo = new T[chromoSize];
    this->size = chromoSize;
    Individual::lowerBound = lowerBound;
    Individual::upperBound = upperBound;

    
}
