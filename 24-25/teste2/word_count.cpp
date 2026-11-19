#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "show_file.h"
using namespace std;

void word_count(const string& input_fname, const string& output_fname){
    ifstream inputFile(input_fname);
    ofstream outputFile(output_fname);

    string line;

    while (getline(inputFile, line)){
        istringstream lineStream(line);
        string word;
        int counter = 0;

        while (lineStream >> word){
            counter++;
        }

        outputFile << counter << endl;
    }
    inputFile.close();
    outputFile.close();
}