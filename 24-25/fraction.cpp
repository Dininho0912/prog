//
// Created by tomas on 13-03-2025.
//

#include <iostream>
#include "fraction.h"
using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;

    return gcd(b, a % b);
}

fraction add(fraction a, fraction b){
    fraction res;

    res.num = a.num * b.den + b.num * a.den;
    res.den = a.den * b.den;

    int g = gcd(res.num, res.den);

    res.num = res.num / g;
    res.den = res.den / g;

    if (res.den < 0){
        res.num = -res.num;
        res.den = -res.den;
    }

    return res;
}

fraction mul(fraction a, fraction b){
    fraction res;

    res.num = a.num * b.num;
    res.den = a.den * b.den;

    int g = gcd(res.num, res.den);

    res.num = res.num / g;
    res.den = res.den / g;

    if (res.den < 0){
        res.num = -res.num;
        res.den = -res.den;
    }

    return res;
}

int main()
{
    { fraction a { 0, 1 }, b { 2, 1};
        std::cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

    { fraction a { 1, 1 }, b { -1, 2};
        std::cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

    { fraction a { -3, 2 }, b { 3, 2 };
        std::cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

    { fraction a { -3, 2 }, b { -2, 3 };
        std::cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

    { fraction a { -7, 24 }, b { 1, 3 };
        std::cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

    { fraction a { -8, 25 }, b { 3, 4 };
        std::cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

    std::cout << add({7,4536}, mul({-5,21}, add({1,2}, mul({-2,3}, {1,9})))) << '\n';

    return 0;
}
