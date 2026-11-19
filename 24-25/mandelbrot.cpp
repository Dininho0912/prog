//
// Created by tomas on 13-03-2025.
//

#include <iostream>
#include "complex.h"

using namespace std;

void add(const complex& a, const complex& b, complex& r){
    r.x = a.x + b.x;
    r.y = a.y + b.y;
}

void mul(const complex& a, const complex& b, complex& r){
    r.x = a.x * b.x - a.y * b.y;
    r.y = a.x * b.y + a.y * b.x;
}

void mandelbrot(const complex&c, unsigned int n, complex & z_n){
    if (n == 0) {
        z_n.x = 0;
        z_n.y = 0;
    } else {
        mandelbrot(c, n - 1, z_n);
        complex temp;
        mul(z_n, z_n, temp);
        add(temp, c, z_n);
    }
}

int main(){
    { complex z_n;
        mandelbrot({1.2, 3.4}, 0, z_n);
        std::cout << z_n << '\n'; }

    { complex z_n;
        mandelbrot({1, 1}, 1, z_n);
        std::cout << z_n << '\n'; }

    { complex z_n;
        mandelbrot({1, 1}, 2, z_n);
        std::cout << z_n << '\n'; }

    { complex z_n;
        mandelbrot({-1.2, 0.4}, 7, z_n);
        std::cout << z_n << '\n'; }

    { complex z_n;
        mandelbrot({0.1, 3.2}, 4, z_n);
        std::cout << z_n << '\n'; }

    { complex z_n;
        mandelbrot({-1, 0}, 11, z_n);
        std::cout << z_n << '\n'; }

    return 0;
}
