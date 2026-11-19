#include <iostream>
using namespace std;

bool isPrime(int num){
    if (num<=1) return false;

    int i=2;

    while (num%i!=0){
        i++;
        continue;
    }

    if (i==num) return true;
    else return false;
}

int main(void){
    int n;
    cin >> n;
    if (isPrime(n)) cout << n << " ";
    else cout << "";

    return 0;
}