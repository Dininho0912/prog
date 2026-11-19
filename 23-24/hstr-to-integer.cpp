#include <iostream>
#include <cmath>
using namespace std;

unsigned long hstr_to_integer(const char hstr[]){
    int i=0, len=-1;
    unsigned long sum = 0;
    
    while (hstr[i]){
        len++;
        i++;
    }

    for(int i=0; hstr[i]!=0; i++, len--){
        char a = hstr[i];
        int e;
        
        if (a>='0' && a<='9'){
            e=a-'0';
        }
        else {
            a=toupper(a);
            e=a-'A'+10;
        }

        sum+=pow(16, len) * e;
    }
    return sum;
}


int main(void){

    cout << hstr_to_integer("0");

    cout << hstr_to_integer("A");

    cout << hstr_to_integer("19");

    cout << hstr_to_integer("fF");

    cout << hstr_to_integer("CafeBabe2022");

    return 0;
}