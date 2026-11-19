#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int count(const string& fname, const string& word){
    ifstream inputFile(fname);

    int counter = 0;

    string cur_word;
    while (inputFile >> cur_word){
        string result1, result2;
        for (char c : cur_word) result1 += tolower(c);
        for (char c : word) result2 += tolower(c);
        if (result1 == result2){
            counter++;
        }
    }
    inputFile.close();
    return counter;
}