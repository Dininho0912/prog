//
// Created by tomas on 17-03-2025.
//

#include<iostream>
#include "print_array.h"
using namespace std;

int expand(const int c[], const int v[], int n, int res[], int max){
    int total = 0;

    for (int i = 0; i < n; i++){
        total += c[i];
    }

    if (total > max){
        return -1;
    }

    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < c[i]; j++){
            res[index++] = v[i];
        }
    }
    return total;
}

int main(){
    { const int n = 1;
        const int c[]{3};
        const int v[]{999};
        const int max = 3;
        int res[max] = {0};
        int len = expand(c, v, n, res, max);
        print_array(res, len); }

    { const int n = 3;
        const int c[n]{3, 2, 1};
        const int v[n]{100, 200, 300};
        const int max = 10; // Bigger than needed
        int res[max] = {0};
        int len = expand(c, v, n, res, max);
        print_array(res, len); }

    { const int n = 1;
        const int c[n]{1};
        const int v[n]{999};
        const int max = 1;
        int res[max] = {0};
        int len = expand(c, v, n, res, max);
        print_array(res, len); }

    { const int n = 2;
        const int c[n]{20, 17};
        const int v[n]{1, 2};
        const int max = 10;
        int res[max] = {0};
        int len = expand(c, v, n, res, max);
        print_array(res, len); }

    { const int n = 4;
        const int c[n]{2, 1, 3, 7};
        const int v[n]{5, 2, 0, -1};
        const int max = 20;
        int res[max] = {0};
        int len = expand(c, v, n, res, max);
        print_array(res, len); }

    return 0;
}