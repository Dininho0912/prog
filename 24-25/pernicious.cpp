//
// Created by tomas on 20-02-2025.
//

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int j = 3; j <= sqrt(n); j += 2){
        if (n % j == 0) return false;
    }
    return true;
}

int oneCounter(int j){
    int sum = 0;

    while (j > 0){
        sum += (j & 1);
        j >>= 1;
    }
    return sum;
}

int main(){
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++){
        int ones = oneCounter(i);
        if (isPrime(ones) && isPrime(i)){
            cout << i << ' ';
        }
    }
    return 0;
}