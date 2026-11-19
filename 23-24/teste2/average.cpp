#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cfloat>
#include "show_file.h"

using namespace std;

void average(const string& input_fname, const string& output_fname){
    ifstream f_in(input_fname);
    ofstream f_out(output_fname);

    int lines=0;

    for(string line; getline(f_in, line); ){
        lines++;
        int count=0;
        double sum=0.0;
        istringstream iss(line);
        for (double x; iss>>x;){
            sum += x;
            count++;
        }
        f_out << fixed << setprecision(3) << sum/count << endl;
    }
    f_out << "lines=" << lines << endl;
}

int main(void){
{ average("p1a-1.txt", "p1a-1_out.txt");
  show_file("p1a-1_out.txt"); }

{ average("p1a-2.txt", "p1a-2_out.txt");
  show_file("p1a-2_out.txt"); }

{ average("p1a-3.txt", "p1a-3_out.txt");
  show_file("p1a-3_out.txt"); }

{ average("p1a-4.txt", "p1a-4_out.txt");
  show_file("p1a-4_out.txt"); }

  return 0;
}