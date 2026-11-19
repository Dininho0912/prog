//
// Created by tomas on 20-02-2025.
//
#include <cmath>
 #include <iostream>
#include <math.h>
using namespace std;


bool isPrime(int n){
    if (n <= 1) return false;

    for (int j = 2; j<=sqrt(n); j++){
        if (n % j == 0) return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;

    for (int i = 2; i <= n; i++){
        if (n <= 1) cout << ' ' ;
        else if (isPrime(i)) cout << i << ' ';
    }
    return 0;
}
