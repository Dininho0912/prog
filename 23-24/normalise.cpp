#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "print.h"
using namespace std;

void normalise(const string& input_fname, const string& output_fname) {
    ifstream input_file(input_fname);
    ofstream output_file(output_fname);

    if (!input_file.is_open()) {
        cerr << "Error: Unable to open input file: " << input_fname << endl;
        return;
    }

    if (!output_file.is_open()) {
        cerr << "Error: Unable to open output file: " << output_fname << endl;
        return;
    }

    string line;
    while (getline(input_file, line)) {
 
        if (line.find_first_not_of(" ") != string::npos) {

            size_t start = line.find_first_not_of(" ");
            size_t end = line.find_last_not_of(" ");
            line = line.substr(start, end - start + 1);
            
            for (char& c : line) {
                c = toupper(c);
            }
            
            output_file << line << endl;
        }
    }

    input_file.close();
    output_file.close();
}

int main() {
    normalise("input.txt", "output.txt");
    print("output.txt");
    return 0;
}