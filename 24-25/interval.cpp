//
// Created by tomas on 06-03-2025.
//

#include <iostream>
#include "interval.h"

using namespace std;

interval intersection(interval a, interval b){
    interval res;

    if (a.end.h < b.start.h || (a.end.h == b.start.h && a.end.m <= b.start.m) ||
        b.end.h < a.start.h || (b.end.h == a.start.h && b.end.m <= a.start.m)){
        return {{0,0}, {0,0}};
    }

    if (a.start.h > b.start.h || (a.start.h == b.start.h && a.start.m > b.start.m)) {
       res.start = a.start;
   } else {
       res.start = b.start;
   }

   // Compute end of intersection
   if (a.end.h < b.end.h || (a.end.h == b.end.h && a.end.m < b.end.m)) {
       res.end = a.end;
   } else {
       res.end = b.end;
   }

   return res;
}


int main()
{
    return 0;
}