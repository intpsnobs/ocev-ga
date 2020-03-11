#include <bits/stdc++.h>
#include "util/freader.cpp"
#include "gene/individual.cpp"

using namespace std;

int main(int argc, const char * argv[]) {

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " config_file\n";
        exit(0);
    }

    Freader * reader = new Freader();

    reader->open("resources/gene.in");

    map<string, string> configurations;

    while (reader->hasContent()) {
        pair<string,string> p = reader->readLine();
        configurations[p.first] = p.second;
    }

    string cod = configurations["COD"];
    int populationSize = stoi(configurations["POP"]);

    vector<Individual<int>*> intRandPopulation(populationSize);
    vector<Individual<int>*> binaryPopulation(populationSize);
    vector<Individual<int>*> intPermutedPopulation(populationSize);
    vector<Individual<double>*> doubleRandPopulation(populationSize);

    cout << "intRandPopulation = [" << endl;
    for (auto& individual : intRandPopulation) {
        individual = new Individual<int>(10, 0, 10, false);
        cout << "\t" << *individual << endl;
    }
    cout << "]\n";

    cout << "binaryPopulation = [" << endl;
    for (auto& individual : binaryPopulation) {
        individual = new Individual<int>(10);
        cout << "\t" << *individual << endl;
    }
    cout << "]\n";

    cout << "doubleRandPopulation = [" << endl;
    for (auto& individual : doubleRandPopulation) {
        individual = new Individual<double>(10, 0, 10, false);
        cout << "\t" << *individual << endl;
    }
    cout << "]\n";

    cout << "intPermutedPopulation = [" << endl;
    for (auto& individual : intPermutedPopulation) {
        individual = new Individual<int>(10, 0, 10, true);
        cout << "\t" << *individual << endl;
    }
    cout << "]\n";

    return 0;
}
