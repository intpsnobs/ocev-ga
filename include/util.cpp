#include "bits/stdc++.h"
#include "Color.h"

using namespace std;

typedef variant<monostate, RandomBinary**, RandomDouble**, RandomInteger**, PermutedInteger**> PopulationType;
typedef map<string,string> Configuration;

vector<string> split(string str, string token=" ") {
    size_t it = str.find(token), last = 0;
    vector<string> vec;
    while (it != string::npos) {
        cout << it << endl;
        vec.push_back(str.substr(last+1, it-1));
        last = it;
        it = str.find(token, ++it);
    }
    vec.push_back(str.substr(last+1, string::npos));
    return vec;
}

void erase(string& str, char token=' ') {
    str.erase(remove_if(str.begin(), str.end(), [&](char c) {return c == token;}), str.end());
}

template<typename T>
void swap(T * a, T * b) {
    T t = *a;
    *a = *b;
    *b = t;
}

PopulationType createRBPopulation(Configuration& config) {
    int populationSize = stoi(config["POP"]);
    int dimension = stoi(config["DIM"]);

    RandomBinary ** population = new RandomBinary*[populationSize];

    for (int i=0; i<populationSize; i++) {
        population[i] = new RandomBinary(dimension);
    }

    return population;
}

PopulationType createRDPopulation(Configuration& config) {
    Color * clr = new Color();
    
    vector<string> range = split(config["REAL"], ",");
    for(string str : range) {
        erase(str, '[');
        erase(str, ']');
    }
    if (range.size() != 2) {
        cerr << clr->setColor(ERR) << "FATAL:\t" << clr->setColor(DEF) << "Bounds could not be defined\n\tCheck configuration file and try again.\n";
        delete clr;
        exit(1);
    }
    double bounds[2] = {stod(range[0]), stod(range[1])};
    if (bounds[1] <= bounds[0]) {
        char c;
        cout << clr->setColor(WAR) << "WARN:\t" << clr->setColor(DEF) << "UpperBound <= LowerBound continue? (UB and LB will swap)\n(y/n)";
        cin >> c;
        if (c != 'y') {
            cerr << clr->setColor(ERR) << "FATAL:\t" << clr->setColor(DEF) << "Bounds could not be defined\n\tCheck configuration file and try again.\n";
            exit(1);
        }
        swap<double>(&bounds[0], &bounds[1]);
    }

    int populationSize = stoi(config["POP"]);
    int dimension = stoi(config["DIM"]);
    
    RandomDouble ** population = new RandomDouble*[populationSize];
    for (int i=0; i < populationSize; i++) {
        population[i] = new RandomDouble(dimension, bounds[0], bounds[1]);
    }
    return population;
}

PopulationType createRIPopulation(Configuration& config) {
    int populationSize = stoi(config["POP"]);
    int dimension = stoi(config["DIM"]);

    Color * clr = new Color();

    vector<string> range = split(config["REAL"], ",");
    if (range.size() != 2) {
        cerr << clr->setColor(ERR) << "FATAL:\t" << clr->setColor(DEF) << "Bounds could not be defined\n\tCheck configuration file and try again.\n";
        delete clr;
        exit(1);
    }
    int bounds[2] = {stoi(range[0]), stoi(range[1])};
    if (bounds[1] <= bounds[0]) {
        char c;
        cerr << clr->setColor(WAR) << "WARN:\t" << clr->setColor(DEF) << "UpperBound <= LowerBound continue? (UB and LB will swap)\n(y/n)";
        cin >> c;
        if (c != 'y') {
            cerr << clr->setColor(ERR) << "FATAL:\t" << clr->setColor(DEF) << "Bounds could not be defined\n\tCheck configuration file and try again.\n";
            exit(1);
        }
        swap<int>(&bounds[0], &bounds[1]);
    }

    RandomInteger ** population = new RandomInteger*[populationSize];
    for (int i=0; i < populationSize; i++) {
        population[i] = new RandomInteger(dimension, bounds[0], bounds[1]);
    }

    return population;
}

PopulationType createPIPopulation(Configuration& config) {
    int populationSize = stoi(config["POP"]);
    int dimension = stoi(config["DIM"]);
    int permuteAmount = stoi(config["D"]);

    PermutedInteger ** population = new PermutedInteger*[populationSize];
    for (int i=0; i < populationSize; i++) {
        population[i] = new PermutedInteger(dimension, 0, permuteAmount-1);
    }

    return population;
}

map<string, PopulationType (*)(Configuration&)> startPopulation = {
    {"BIN", &createRBPopulation},
    {"REAL", &createRDPopulation},
    {"INT-PERM", &createRIPopulation},
    {"PERM", &createPIPopulation}
};

