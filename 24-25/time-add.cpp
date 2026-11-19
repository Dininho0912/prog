//
// Created by tomas on 17-03-2025.
//

#include <iostream>
using namespace std;

int main(){
    int h, m, delta;
    cin >> h >> m >> delta;

    m += delta;
    while (m >= 60){
        m -= 60;
        h++;
    }
    if (h >= 24){
        h -= 24;
    }
    cout << h << " " << m << endl;
    return 0;
}