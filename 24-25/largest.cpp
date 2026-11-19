//
// Created by tomas on 17-03-2025.
//

#include <iostream>
#include "interval.h"
using namespace std;

interval largest(const interval a[], int n){
    interval res = a[0];

    int gap = (a[0].end.h * 60 + a[0].end.m) - (a[0].start.h * 60 + a[0].start.m);

    if (n == 1) return a[0];

    for (int i = 1; i < n; i++){
        int nGap = (a[i].end.h * 60 + a[i].end.m) - (a[i].start.h * 60 + a[i].start.m);

        if (nGap > gap){
            gap = nGap;
            res = a[i];
        }
    }
    return res;
}

int main(){
    { const int n = 1;
        interval a[n] = {  { { 12, 30 }, { 12, 55 } }  };
        std::cout << largest(a, n) << '\n'; }

    { const int n = 4;
      interval a[n] = {  { { 0,  0  },   { 0,  1 }  },
                         { { 0,  0  },   { 23, 59 } },
                         { { 23, 57 },   { 23, 59 } },
                         { { 0,  1  },   { 23, 59 } } };
      std::cout << largest(a, n) << '\n'; }

    { const int n = 5;
      interval a[n] = {  { { 12,  59 }, { 13, 4  } },
                         { { 0,   0  }, { 0,  4  } },
                         { { 23,  56 }, { 23, 59 } },
                         { { 13,  30 }, { 13, 32 } },
                         { { 18,  59 }, { 19, 0  } } };
      std::cout << largest(a, n) << '\n'; }

    { const int n = 5;
      interval a[n] = {  { { 12,  59 }, { 13, 4  } },
                         { { 0,   0  }, { 0,  4  } },
                         { { 23,  53 }, { 23, 59 } },
                         { { 13,  29 }, { 13, 31 } },
                         { { 18,  59 }, { 19, 0  } } };
      std::cout << largest(a, n) << '\n'; }

    { const int n = 5;
      interval a[n] = {  { { 12,  59 }, { 13, 4  } },
                         { { 0,   0  }, { 0,  4  } },
                         { { 23,  53 }, { 23, 59 } },
                         { { 13,  29 }, { 13, 31 } },
                         { { 18,  58 }, { 19, 5  } } };
      std::cout << largest(a, n) << '\n'; }

    return 0;
}
