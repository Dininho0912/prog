#include <iostream>
#include <vector>
#include <string>
#include "print_string.h"
using namespace std;

void split(const string& s, vector<string>& v) {
    v.clear();

    size_t start = s.find_first_not_of(' ');

    if (start == string::npos) {
        return;
    }

    size_t end = s.find_first_of(' ', start);

    while (start != string::npos) {
        v.push_back(s.substr(start, end - start));

        start = s.find_first_not_of(' ', end);

        if (start == string::npos) {
            break;
        }

        end = s.find_first_of(' ', start);
    }
}

int main() {

{ string s = "";
  vector<string> v;
  split(s, v);
  print(v); }

{ string s = "    ";
  vector<string> v;
  split(s, v);
  print(v); }

{ string s = "  a b  c ";
  vector<string> v;
  split(s, v);
  print(v); }

{ string s = "C++ LEIC FCUP FEUP";
  vector<string> v;
  split(s, v);
  print(v); }

{ string s = "       C++        ";
  vector<string> v;
  split(s, v);
  print(v); }

    return 0;
}