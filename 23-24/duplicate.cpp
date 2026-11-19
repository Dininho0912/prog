#include <iostream>
using namespace std;

char* duplicate(const char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    char* dup = new char[len + 1];

    for (int v = 0; v < len; v++) {
        dup[v] = s[v];
    }
    
    dup[len] = '\0';

    return dup;
}

int main(void){
    { char* s = duplicate("");
      cout << "\"" << s << "\"\n";
      delete [] s; }

    { char* s = duplicate("a");
      cout << "\"" << s << "\"\n";
      delete [] s; }

    { char* s = duplicate("C++");
      cout << "\"" << s << "\"\n";
      delete [] s; }

    { char* s = duplicate("0123 456 789 @ abc");
      cout << "\"" << s << "\"\n";
      delete [] s; }

      return 0;
}