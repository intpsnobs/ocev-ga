#include "bits/stdc++.h"

using namespace std;

vector<string> split(string str, string token=" ") {
    size_t it = str.find(token);
    vector<string> vec;
    while (it != string::npos) {
        vec.push_back(str.substr(0, it));
        str.find(token, ++it);
    }    
    return vec;
}

template<typename T>
void swap(T * a, T * b) {
    T t = *a;
    *a = *b;
    *b = t;
}