#include <bits/stdc++.h>
#include "../include/Allele.h"
#include "../include/Color.h"

using namespace std;

template<typename T>
void GA(T ** population, int size) {
    for (int i=0; i < size; i++) {
        cout << *population[i] << endl;
    }
}
