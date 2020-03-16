#include <bits/stdc++.h>

#include "../include/Freader.h"
#include "../include/Allele.h"
#include "../include/Validator.h"
#include "../include/Color.h"
#include "../include/util.cpp"

using namespace std;

#define DEF 0   // Reset
#define ERR 41  // Red bg
#define LOG 42  // Green bg
#define WAR 43  // Yellow bg

int main(int argc, const char * argv[]) {

    Color * clr = new Color();

    if (argc < 2) {
        cerr << clr->setColor(WAR) << "USAGE:\t" << clr->setColor(DEF) << argv[0] << " config_file\n";
        delete clr;
        exit(1);
    }
    string configFile = argv[1];
    Freader * reader = new Freader();
    
    if (!reader->open(configFile)) {
        cerr << clr->setColor(ERR) << "FATAL:\t" << clr->setColor(DEF) << "Could not open configuration file \"" << configFile << "\"\n\t";
        cerr << "Check paths and try again.\n";
        exit(1);
    }

    map<string, string> * configurations = new map<string, string>();

    while (reader->hasContent()) {
        pair<string,string> p = reader->readLine();
        if (p.first == "" || p.second == "") continue;
        (*configurations)[p.first] = p.second;
        cout << p.first << " " << p.second << "\n";
    }

    string cod = (*configurations)["COD"];
    int populationSize = stoi((*configurations)["POP"]);
    int dimension = stoi((*configurations)["D"]);
    
    if (configurations->find("BIN") != configurations->end()) {
        RandomBinary ** population = (RandomBinary**)malloc(sizeof(RandomBinary*) * populationSize);
        for (int i=0; i<populationSize; i++) {
            population[i] = new RandomBinary(dimension);
        }
        
    } else if (configurations->find("REAL") != configurations->end()) {

        vector<string> range = split((*configurations)["REAL"], ",");

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

        RandomDouble ** population = (RandomDouble**)malloc(sizeof(RandomDouble*) * populationSize);
        for (int i=0; i<populationSize; i++) {
            population[i] = new RandomDouble(dimension, bounds[0], bounds[1]);
        }

    } else if (configurations->find("INT") != configurations->end()) {
        // TODO bo muça vei
    }



    delete clr;
    delete reader;
    delete configurations;
    
    // RandomInteger randomInteger(10,0,10);
    // cout<<randomInteger<<endl;
    // RandomDouble randomDouble(10,0,10);
    // cout<<randomDouble<<endl;
    // RandomBinary randomBinary(10);
    // cout<<randomBinary<<endl;
    // PermutedInteger permutedInteger(10, 1, 10);
    // cout<<permutedInteger<<endl;

    return 0;
}
