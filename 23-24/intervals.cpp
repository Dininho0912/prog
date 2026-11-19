#include <iostream>
#include "interval.h"
#include <cmath>
using namespace std;

int to_minutos(time_of_day x){
    int minutos=0;
    minutos=x.h*60+x.m;
    return minutos;
}

int search_intervals(time_of_day t, const interval a[], int n, interval& u){
    int sum = 0; 
    
    u = {t,t};
    
    for (int i=0; i<n; i++){

        if (to_minutos(a[i].start)<=to_minutos(t) && to_minutos(a[i].end)>to_minutos(t)){
            u.start=(to_minutos(u.start)>to_minutos(a[i].start)) ? a[i].start : u.start;
            u.end=(to_minutos(u.end)<to_minutos(a[i].end)) ? a[i].end : u.end;
        }
        else {
            continue;
        }     
    }

    sum = to_minutos(u.end)-to_minutos(u.start);
    return sum;
}














int main(void){
{ const int n = 1;
  const time_of_day t = { 13, 00 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; }

{ const int n = 2;
  const time_of_day t = { 14, 30 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; }

{ const int n = 2;
  const time_of_day t = { 12, 30 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; }

{ const int n = 2;
  const time_of_day t = { 15, 30 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; } 

{ const int n = 5;
  const time_of_day t = { 15, 15 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } }, 
                  { { 15, 10 }, { 16, 10 } }, 
                  { {  9, 30 }, { 15, 15 } }, 
                  { {  9, 45 }, { 15, 16 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; } 
  return 0;
}