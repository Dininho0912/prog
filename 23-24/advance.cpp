#include <iostream>
using namespace std;

bool bissexto(int y) {
    if (y%4==0 ){ 
        return true;
    }
    else {
        return false;
    }
}

void advance(int delta, int& d, int& m, int& y) {
    int x;
    d=d+delta;
    x=delta/365;

    if (x>=1){     
        y=y+x;
        d=d-365*x;
    }

    if (m==2 && bissexto(y)==false && d>28){
        m=m+1;
        d=d-28;
    }

    while (d>31){

    if (m==2 && bissexto(y)==true &&d>29){
        m=m+1;
        d=d-29;
    } 

    if ((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && d>31){
        m=m+1;
        d=d-31;
    }
    else if (m!=2 && d>30){
        m=m+1;
        d=d-30;
    }

    if (m>12){
        m=m-12;
        y=y+1;
    }
    }

}

int main(void){
{ int d = 1, m = 1, y = 2022; 
  advance(0, d, m, y); 
  cout << d << ' ' << m << ' ' << y << '\n'; }
{ int d = 1, m = 10, y = 2022; 
  advance(10, d, m, y); 
  cout << d << ' ' << m << ' ' << y << '\n'; }
{ int d = 2, m = 6, y = 2022; 
  advance(31, d, m, y); 
  cout << d << ' ' << m << ' ' << y << '\n'; }
{ int d = 2, m = 7, y = 2022; 
  advance(31, d, m, y); 
  cout << d << ' ' << m << ' ' << y << '\n'; }
{ int d = 25, m = 2, y = 2000; 
  advance(4, d, m, y); 
  cout << d << ' ' << m << ' ' << y << '\n'; }
{ int d = 25, m = 2, y = 2001; 
  advance(4, d, m, y); 
  cout << d << ' ' << m << ' ' << y << '\n'; }
{ int d = 2, m = 12, y = 1900; 
  advance(365 + 5, d, m, y); 
  cout << d << ' ' << m << ' ' << y << '\n';}

{ int d = 31, m = 3, y = 1903; 
  advance(365 + 366 + 30 + 5, d, m, y); 
  cout << d << ' ' << m << ' ' << y << '\n'; }
  return 0;
}
