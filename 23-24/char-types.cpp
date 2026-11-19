#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int letters=0, digits=0, neither=0;

    for (int i=0; i<n; i++){
        char c;
        cin >> c;
        if (c>='0' && c<='9') digits+=1;

        else if ((c>='a' && c<='z') || (c>='A' && c<='Z')) letters+=1;

        else neither+=1;

    }
    cout << letters << ' ' << digits << ' ' << neither << '\n';
    return 0;
}