#include <iostream>
#include "cdata.h"
using namespace std;

int* expand_cdata(const cdata a[], int n){ 
    int tam=0;
    for (int x=0; x<n; x++){
        tam+=a[x].count;
    }
    int* p = new int[tam];

    int i=0;

    for(int m=0; m<n; m++){
        for (int q=0; q<a[m].count; q++){
            p[i]=a[m].value;
            i++;
        }
    }
    return p;
}





int main(void){
    { const int n = 1;
      const cdata a[] { { 3, 999 } };
      int* r = expand_cdata(a, n);
      print_array(r, 3);
      delete [] r; }

    { const int n = 3;
      const cdata a[] { { 3, 100 }, { 2, 200 }, { 1, 300 } };
      int* r = expand_cdata(a, n);
      print_array(r, 6);
      delete [] r; } 

    { const int n = 1;
      const cdata a[] { { 1, 999 } };
      int* r = expand_cdata(a, n);
      print_array(r, 1);
      delete [] r; }

    { const int n = 2;
      const cdata a[] { { 20, 1 }, { 17, 2} };
      int* r = expand_cdata(a, n);
      print_array(r, 37);
      delete [] r; } 

    { const int n = 4;
      const cdata a[] { { 2, 5 }, { 1, 2 }, { 3, 0 }, { 7, -1 } };
      int* r = expand_cdata(a, n);
      print_array(r, 13);
      delete [] r; }

    return 0;
}