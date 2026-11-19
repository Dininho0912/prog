//
// Created by tomas on 04-03-2025.
//

#include <iostream>
#include <cmath>
using namespace std;

long factorial(const int n){
    long f = 1;
    for (int i = 1; i <= n; ++i) f *=i;
    return f;
}

unsigned long bc(unsigned long n, unsigned long k){
    return factorial(n) / (factorial(k) * factorial(n-k));
}

int main(){
    return 0;
}