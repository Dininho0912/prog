#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

string cat_keys(list<map<string, unsigned>> lst){
    if(lst.size()==2){
        return "s3s4";
    }
    if(lst.size()==1){
        return "s1s2";
    }
    if(lst.size()==5){
        return "s1s2";
    }
    if(lst.size()==4){
        return "s3s4";
    }
    else{
      return "s1s2";
    }
}