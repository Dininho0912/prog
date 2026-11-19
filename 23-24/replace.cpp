#include <iostream>
#include <map>
#include <string>
using namespace std;

void replace(const map<char, char>& r, string& s){
    for (char& c : s) {
        auto it = r.find(c);
        if (it != r.end()) {
            c = it->second;
        }
    }
}