#include <iostream>
#include "alist.h"
using namespace std;

void append(alist* a, const alist* b){
    if (b->size == 0) return;

    int new_len = a->size + b->size, count=0;

    int *c=new int [new_len];

    for (int i=0; i<a->size; i++) c[count++]=a->elements[i];

    for (int i=0; i<b->size; i++) c[count++]=b->elements[i];

    delete[] a->elements;

    a->elements=c;
    a->size=new_len;
} 



int main(void){
{ alist* a = empty();
  const alist* b = empty();
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }

{ alist* a = empty();
  const int nB = 2;
  int eB[nB] = { 1, 2 };
  const alist* b = build(nB, eB);
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }

{ const int nA = 2;
  int eA[nA] = { 1, 2 }; 
  alist* a = build(nA, eA);
  const alist* b = empty();
  append(a, b);
  print(a);
  destroy(a); 
  destroy(b); }

{ const int nA = 2;
  int eA[nA] = { 1, 2 };
  alist* a = build(nA, eA);
  const int nB = 3;
  int eB[nB] = { 3, 4, 5 };
  const alist* b = build(nB, eB);
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }

{ const int nA = 4;
  int eA[nA] = { 1, 2, 3, 4 };
  alist* a = build(nA, eA);
  const int nB = 3;
  int eB[nB] = { 5, 6, 7 };
  const alist* b = build(nB, eB);
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }
    
    return 0;

}