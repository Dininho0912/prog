#include <iostream>
#include <algorithm>
using namespace std;

int median(const int a[], int n){
    int* tmp=new int[n];
    int mid=0;
    for (int m=0; m<n; m++){
        tmp[m]=a[m];
    }

    sort(tmp, tmp+n);

    if(n%2!=0){
        mid=tmp[n/2];
    }
    else if(n%2==0){
        mid=(tmp[n/2-1]+tmp[n/2])/2;
    }
    delete [] tmp;
    return mid;
}

int main(void){
{ const int n = 5; 
  int a[n] { 10, -10, 0, 12, 11 };
  cout << median(a, n) << '\n'; }

{ const int n = 6; 
  int a[n] { 30, 10, 0, -20, 14, 20 };
  cout << median(a, n) << '\n'; }

{ const int n = 1; 
  int a[n] { 99 };
  cout << median(a, n) << '\n'; }

{ const int n = 2; 
  int a[n] { 101, 99 };
  cout << median(a, n) << '\n'; }
    
    return 0;
}