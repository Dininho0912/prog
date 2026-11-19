#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void) {
    int k, d;
    double x=0.0;

    cin >> k;
    cin >> d;

    for (int i=0; i<=k; i++) {
        x+=4*pow(-1, i)/(2*i+1);
    }
    
    cout << fixed << setprecision(d) << x;
    
    return 0;
}