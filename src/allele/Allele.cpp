
template<typename  T>
class Allele{
    public:
        int genSize;
        T lowerBound;
        T upperBound;
        T * gen;

        Allele(int genSize, T lowerBound = 0, T upperBound = 1){
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
