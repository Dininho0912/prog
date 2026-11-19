#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int solve_eq(int a, int b, int c, double& x1, double& x2){
    int delta = b*b-4*a*c;
    int soluções;
    
    if (delta<0){
        soluções=0;
        x1=x2=NAN;
        
    }
    else if (delta==0){
        soluções=1;
        x1=-b/(2.0*a);
        x2=NAN;
    }
    else {
        soluções =2;
        x1=(-b-sqrt(delta))/(2*a);
        x2=(-b+sqrt(delta))/(2*a);
    }
    return soluções;
}

int main(void){
    { double x1, x2; 
      int r = solve_eq(1, 1, 0, x1, x2); 
      cout << fixed << setprecision(7) 
           << r << ' ' << x1 << ' ' << x2 << '\n'; }

    { double x1, x2; 
      int r = solve_eq(1, -2, 1, x1, x2); 
      cout << fixed << setprecision(7) 
         << r << ' ' << x1 << ' ' << x2 << '\n'; }

    { double x1, x2; 
      int r = solve_eq(1, 1, 1, x1, x2); 
      cout << fixed << setprecision(7) 
           << r << ' ' << x1 << ' ' << x2 << '\n'; }

    { double x1, x2; 
      int r = solve_eq(1, -1, 0, x1, x2); 
      cout << fixed << setprecision(7) 
           << r << ' ' << x1 << ' ' << x2 << '\n'; }

    { double x1, x2; 
      int r = solve_eq(3, 4, -2, x1, x2); 
      cout << fixed << setprecision(7) 
           << r << ' ' << x1 << ' ' << x2 << '\n'; }
    
    return 0;
        
    }