#include <bits/stdc++.h>
#include "gene/individual.cpp"

using namespace std;

int main(int argc, char * argv[]) {

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " config_file\n";
        exit(0);
    }
    Individual<int> intRand(10,0,10,false);
    cout<<intRand<<endl;
    Individual<int> binary(10);
    cout<<binary<<endl;
    Individual<double> doubleRand(10,0,10,false);
    cout<<doubleRand<<endl;
    return 0;
}
