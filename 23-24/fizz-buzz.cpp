#include <iostream>
using namespace std;

int main(void){
    int num;
    int i=1;
    cin >> num;

    while(i<=num){
        
        if (i%3==0 && i%5==0){
            cout << "";
            i++;
        }
        else if (i%3==0){
            cout << "Fizz ";
            i++;
        }
        else if (i%5==0){
            cout << "Buzz ";
            i++;
        }
        else {
            cout << i << " ";
            i++;
        }
    }
    return 0;
}