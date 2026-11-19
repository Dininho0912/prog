#include <iostream>
#include <cctype>
using namespace std;

int check(char target, int alpha_pos[]){
    target=tolower(target);
    if (alpha_pos[target-'a']==1)
        return 0;
    alpha_pos[target-'a']=1;
        return 1;
}

bool pangram(const char s[], char m[]){
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    int alpha_pos[26]={0};
    int i=0;
    int count=0;
    int m_length=0;
    while (s[i] !='\0'){
        if (s[i]!=' ') count+=check(s[i], alpha_pos);
        i++;
    }
            
    if (count == 26){
        m[0]='\0';
        return true;
    }

    for (int i=0; i<26; i++){
        if (alpha_pos[i]==0){
            m[m_length]=alphabet[i];
            m_length++;
        }
    }
    m[m_length]='\0';
    return false;
}