#include <bits/stdc++.h>
#include <variant>

#include "../include/Freader.h"
#include "../include/Allele.h"
#include "../include/Validator.h"
#include "../include/Color.h"
#include "../include/util.cpp"
#include "../include/genetic.cpp"


using namespace std;

template<typename T>
void loop(T ** population) {

}

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

    map<string, string> configurations;// = new map<string, string>();

    while (reader->hasContent()) {
        pair<string,string> p = reader->readLine();
        if (p.first == "" || p.second == "") continue;
        configurations[p.first] = p.second;
    }

    string cod = configurations["COD"];
    int populationSize = stoi(configurations["POP"]);

    PopulationType genericPopulation = startPopulation[cod](configurations); 
    
    auto rb = get_if<RandomBinary**>(&genericPopulation);
    auto rd = get_if<RandomDouble**>(&genericPopulation);
    auto ri = get_if<RandomInteger**>(&genericPopulation);
    auto pi = get_if<PermutedInteger**>(&genericPopulation);

    if (rb != nullptr) {
        GA<RandomBinary>(*rb, populationSize);
    } else if (rd != nullptr) {
        GA<RandomDouble>(*rd, populationSize);
    } else if (ri != nullptr) {
        GA<RandomInteger>(*ri, populationSize);
    } else if (pi != nullptr) {
        GA<PermutedInteger>(*pi, populationSize);
    } else {
        cerr << clr->setColor(ERR) << "FATAL:\t" << clr->setColor(DEF) << "Could not start Genetic Algorithm\n";
    }
    
    delete clr;
    delete reader;
    
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
