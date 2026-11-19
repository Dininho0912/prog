//
// Created by tomas on 20-02-2025.
//

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int k, d;
    cin >> k >> d;

    double x = 0.0;

    for (int n = 0; n <= k; n++){
        x += 4*(pow(-1,n))/(2*n + 1);
    }

    cout << fixed << setprecision(d) << x << endl;
    return 0;
}