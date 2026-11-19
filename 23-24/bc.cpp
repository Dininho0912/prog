#include <iostream>
using namespace std;

unsigned long bc(unsigned long n, unsigned long k){
    unsigned long num = 1;
    unsigned long den = 1;
    
    for (unsigned long i=1; i<=k; i++){
        num *=(n-i+1);
        den *=i;
    }
    return num/den;
}

int main(){
    cout << bc(5, 0) << '\n';

    cout << bc(5, 1) << '\n';

    cout << bc(5, 5) << '\n'; 

    cout << bc(5, 2) << '\n';

    cout << bc(12, 7) << '\n';

    cout << bc(20, 10) << '\n'; 

    return 0;
}