#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include "show_file.h"

using namespace std;

void calc_medians(const string& input_fname, const string& output_fname) {
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
        if (line.empty() || line[0] == '#') // Skip empty lines and comment lines
            continue;

        istringstream iss(line);
        string identifier;
        iss >> identifier;

        vector<double> values;
        double value;
        while (iss >> value) {
            values.push_back(value);
        }

        if (values.empty()) {
            cerr << "Warning: No values found for identifier '" << identifier << "'. Skipping." << endl;
            continue;
        }

        sort(values.begin(), values.end());

        double median;
        if (values.size() % 2 == 0) {
            median = 0.5 * (values[values.size() / 2 - 1] + values[values.size() / 2]);
        } else {
            median = values[values.size() / 2];
        }

        output_file << fixed << setprecision(1) << identifier << " " << median << endl;
    }

    input_file.close();
    output_file.close();
}

int main() {
    calc_medians("input.txt", "output.txt");
    show_file("output.txt");
    return 0;
}