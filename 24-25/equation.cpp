//
// Created by tomas on 04-03-2025.
//

#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

int solve_eq(int a, int b, int c, double& x1, double& x2){
    double delta = 0;
    delta = pow(b,2) - 4 * a * c;

    if (delta < 0)
    {
        x1 = NAN;
        x2 = NAN;
        return 0;
    }
    else if (delta == 0)
    {
        x1 = (-b)/(2.0*a);
        x2 = NAN;
        return 1;
    }
    else
    {
        x1 = (-b-sqrt(delta))/(2*a);
        x2 = (-b+sqrt(delta))/(2*a);
        return 2;
    }

}
int main(){
    { double x1, x2;
        int r = solve_eq(1, 1, 0, x1, x2);
        std::cout << fixed << setprecision(7)
             << r << ' ' << x1 << ' ' << x2 << '\n'; }

    { double x1, x2;
        int r = solve_eq(-9, 6, -1, x1, x2);
        std::cout << fixed << setprecision(7)
             << r << ' ' << x1 << ' ' << x2 << '\n'; }

    { double x1, x2;
        int r = solve_eq(1, 1, 1, x1, x2);
        std::cout << fixed << setprecision(7)
             << r << ' ' << x1 << ' ' << x2 << '\n'; }

    { double x1, x2;
        int r = solve_eq(1, -1, 0, x1, x2);
        std::cout << fixed << setprecision(7)
             << r << ' ' << x1 << ' ' << x2 << '\n'; }

    { double x1, x2;
        int r = solve_eq(3, 4, -2, x1, x2);
        std::cout << fixed << setprecision(7)
             << r << ' ' << x1 << ' ' << x2 << '\n'; }
    return 0;
}