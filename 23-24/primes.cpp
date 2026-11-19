#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;  
    }

    int sqrtNum = sqrt(num);
    for (int i = 2; i <= sqrtNum; ++i) {
        if (num % i == 0) {
            return false;  
        }
    }

    return true;  
}

int main() {
    int n;

    cin >> n;

    for (int i=2; i<=n; i++) {
        if (n<=1) {
            cout << " ";
        }
        else if (isPrime(i)){
            cout << i << " ";
        }
    }
    return 0;
}

