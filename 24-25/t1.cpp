//
// Created by tomas on 27-02-2025.
//

#include <iostream>
using namespace std;

int g(int x, int& c)
{
    c++;
    if (x <= 1) return x;
    else return g(x - 1, c) + g(x - 2, c);
}

int g(int n)
{
    int c = 0;
    int r = g(n, c);
    return r + c;
}
int main(){
    cout << g(3);
    return 0;
}