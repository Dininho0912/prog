//
// Created by tomas on 20-02-2025.
//

#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int digits = 0, letters = 0, neither = 0;

  for (int i = 0; i < N; i++) {
    char a;
    cin >> a;

    if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
      letters++;
    } else if(a >= '0'  && a <= '9') {
      digits++;
    } else {
      neither++;
    }
  }
  cout << letters << ' ' << digits << ' ' << neither << endl;
  return 0;
}