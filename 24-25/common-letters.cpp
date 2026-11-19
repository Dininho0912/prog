//
// Created by tomas on 17-03-2025.
//

#include <iostream>
using namespace std;

int common_letters(const char a[], const char b[], char out[]){
    bool presentA[26] = {false}, presentB[26] = {false};

    for (int i = 0; a[i] != '\0'; i++){
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z')){
            char lower = (a[i] >= 'A' && a[i] <= 'Z') ? (a[i] + 32) : a[i];
            presentA[lower - 'a'] = true;
        }
    }

    for (int i = 0; b[i] != '\0'; i++){
        if ((b[i] >= 'A' && b[i] <= 'Z') || (b[i] >= 'a' && b[i] <= 'z')){
            char lower = (b[i] >= 'A' && b[i] <= 'Z') ? (b[i] + 32) : b[i];
            presentB[lower - 'a'] = true;
        }
    }

    int count = 0;
    for (int i = 0; i <26; i++){
        if (presentA[i] && presentB[i]){
            out[count++] = 'a' + i;
        }
    }

    out[count] = '\0';
    return count;
}

int main(){
    { char out[26+1];
        int n = common_letters("+LEIC", "c++", out);
        std::cout << n << " \"" << out << "\"\n"; }

    { char out[26+1];
        int n = common_letters("LEIC @ UP", "XY ZZZ++", out);
        std::cout << n << " \"" << out << "\"\n"; }

    { char out[26+1];
        int n = common_letters("", "abcdefghi JKLMNOPQRSTUVWXyz", out);
        std::cout << n << " \"" << out << "\"\n"; }

    { char out[26+1];
        int n = common_letters("JKLMNOPQRSTUVWXyz ABCDE fghi", "abcdefghi JKLMNOPQRSTUVWXyz", out);
        std::cout << n << " \"" << out << "\"\n"; }

    { char out[26+1];
        int n = common_letters("J LMNOP RSTUVWXyz ABCDE fghi", "a cdefghi JKL NOPQRS UVWXy", out);
        std::cout << n << " \"" << out << "\"\n"; }

    { char out[26+1];
        int n = common_letters("abcdefgh 12345 JKLMNOPQRSTUVWXyz abcdefgh JKLMNOPQRSTUVWXyz", "zzzz abcdefghi JKLMNOPQRSTUVWXz", out);
        cout << n << " \"" << out << "\"\n"; }
    return 0;
}