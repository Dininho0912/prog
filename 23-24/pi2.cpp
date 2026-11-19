#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void){
    int k, d;
    double x=0.0;
    cin >> k >> d;
    
    for (int n=0; n<=k; n++){
        x+=4*pow(-1,n)/(2*n+1);
    }
    cout << fixed << setprecision(d) << x;
    return 0;
}