//
// Created by tomas on 06-03-2025.
//

#include <iostream>
#include "time_of_day.h"
using namespace std;

time_of_day tick(time_of_day t){
    t.m++;

    if (t.m > 59)
    {
        t.m = 0;
        t.h ++;
    }
    if (t.h > 23){
        t.h=0;
    }
    return t;
}

int main(){
    return 0;
}