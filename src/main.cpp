#include <bits/stdc++.h>

#include "../include/Freader.h"
#include "../include/Allele.h"

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
        if (p.first == "" || p.second == "") continue;
        configurations[p.first] = p.second;
    }

    string cod = configurations["COD"];
    int populationSize = stoi(configurations["POP"]);

    RandomInteger randomInteger(10,0,10);
    cout<<randomInteger<<endl;
    RandomDouble randomDouble(10,0,10);
    cout<<randomDouble<<endl;
    RandomBinary randomBinary(10);
    cout<<randomBinary<<endl;
    PermutedInteger permutedInteger(10, 1, 10);
    cout<<permutedInteger<<endl;

    return 0;
}
