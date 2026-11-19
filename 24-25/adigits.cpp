//
// Created by tomas on 27-02-2025.
//

#include <iostream>
using namespace std;

int adigits(int a, int b, int c)
{
    int max, mid, min;

    if (a >= b && a >= c) max = a;
    else if (b >= a && b >= c) max = b;
    else max = c;

    if (a <= b && a <= c) min = a;
    else if (b <= a && b <= c) min = b;
    else min = c;

    if ((a == max && b == min) || (b == max && a == min)) mid = c;
    else if ((b == max && c == min) || ( b == min && c == max)) mid = a;
    else mid = b;
    return max * 100 + mid * 10 + min;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    adigits(a,b,c);
    return 0;
}