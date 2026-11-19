#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "wc.h"

using namespace std;

wcresult wc(const string& filename){
    ifstream inputFile(filename);
    wcresult result = {0, 0, 0};
    string line;

    while (getline(inputFile,line)){
        result.lines++;

        istringstream iss(line);
        string word;

        while (iss >> word){
            result.words++;
        }
        result.bytes += line.size() + 1;
    }
    inputFile.close();
    return result;
}