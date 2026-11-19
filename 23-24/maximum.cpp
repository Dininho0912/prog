#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include "show_file.h"
using namespace std;

void maximum(const string& input_fname, const string& output_fname) {
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

    vector<double> values;
    double value;
    while (input_file >> value) {
        value = round(value * 1000) / 1000.0;
        values.push_back(value);
    }

    if (values.empty()) {
        cerr << "Error: No values found in input file." << endl;
        return;
    }

    sort(values.begin(), values.end(), less<double>()); 

    output_file << fixed << setprecision(3);
    for (double val : values) {
        output_file << val << endl;
    }
    output_file << "count=" << values.size() << "/max=" << values.back();

    input_file.close();
    output_file.close();
}

int main() {
    maximum("input.txt", "output.txt");
    show_file("output.txt");
    return 0;
}