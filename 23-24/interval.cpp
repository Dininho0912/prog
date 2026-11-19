#include "interval.h"
#include <iostream>
using namespace std;

int comp(time_of_day a,time_of_day b){

    if (a.h>b.h) return true;
    else if (a.h == b.h && a.m >=b.m) return true;
    else return false;
}

interval intersection(interval a, interval b){
    time_of_day start,end;
    if(comp(a.start,b.end) || comp(b.start, a.end)){
        return {{00,00},{00,00}};
    }
    else {
        if (comp(a.start,b.start))
            start = a.start;
        else
        start = b.start;
        if (comp(b.end,a.end))
            end = a.end;
        else
            end = b.end;
        return {start,end};
    }
}




int main(){
    cout << intersection( { { 12, 30 }, { 14, 30 } },{ { 17, 30 }, { 18, 30 } } ) << '\n';

cout << intersection( { { 12, 30 }, { 14, 30 } }, { { 14, 30 }, { 18, 30 } } ) << '\n';

cout << intersection( { { 12, 30 }, { 14, 31 } } ,{ { 14, 30 }, { 18, 30 } } ) << '\n';

cout << intersection( { { 14, 30 }, { 15, 59 } },  { { 11, 30 }, { 14, 31 } } ) << '\n';

cout << intersection( { {  4, 30 }, {  7, 59 } },  { {  4,  0 }, {  7, 29 } } ) << '\n';

cout << intersection( { { 23,  0 }, { 23, 58 } }, { { 22, 45 }, { 23, 59 } } ) << '\n';

cout << intersection( { { 17,  0 }, { 19,  0 } }, { { 15,  0 }, { 17,  0 } } ) << '\n';
return 0;
}


