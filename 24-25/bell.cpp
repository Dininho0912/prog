//
// Created by tomas on 04-03-2025.
//

#include <iostream>
using namespace std;

 unsigned long factorial(const int n){
    long f = 1;
    for (int i = 1; i <= n; ++i) f *=i;
    return f;
}

unsigned long bc(unsigned long n, unsigned long k){
    return factorial(n) / (factorial(k) * factorial(n-k));
}

unsigned long bell(unsigned long n){
    unsigned long res = 0;
     if (n == 0 || n == 1) return 1;
    for (unsigned long k = 0; k <= n-1; k++)
    {
        res += bc(n-1.0, k) * bell(k);
    }
    return res;
}

int main()
{
    return 0;
}