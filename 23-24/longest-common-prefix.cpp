#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longest_prefix(const vector<string>& v){
    if (v.empty()) {
        return "";
    }

    string shortest = v[0];
    for (const string& s : v) {
        if (s.length() < shortest.length()) {
            shortest = s;
        }
    }

    for (size_t i = 0; i < shortest.length(); ++i) {
        char ch = shortest[i];
        for (const string& s : v) {
            if (s[i] != ch) {
                
                return shortest.substr(0, i);
            }
        }
    }
    return shortest;
}


int main(void){
cout << "\"" << longest_prefix({ "apple", "apply", "ape", "april" }) << "\"\n";

cout << "\"" << longest_prefix({ "ap", "apple", "apply", "ape", "april", "aq", "x" }) << "\"\n";

cout << "\"" << longest_prefix({ "geezer", "geeksforgeeks", "geeks", "geek",  }) << "\"\n";

cout << "\"" << longest_prefix({ "sedatesingratiateconcomitant", "sedatesparleypoliteness", "sedateselbowsHahn", "sedatesgloweringimbecility's", "sedatesbuttershexing", "sedatesKwangju'smulch's", "sedatesunwiserN", "sedatesprepossessedboggles", "sedatesinterrelationshipdialings", "sedatesgropesNelsen's", "sedatesMayfaircondemnations" }) << "\"\n";

cout << "\"" << longest_prefix({ "symmetricstalwartscorn'flowers", "symmetricShetland'ssuccessfully", "symmetricreceiver'shipsteed", "symmetricGrailsflown", "symmetricpromenadingoutflank", "symmetricdrugg'ingseizure", "symmetricsanctumsove'rprinting", "symmetricCitroentransgr'essed", "symmetricdissembledwinging", "symmetric'recoupingCinderella" }) << "\"\n";
return 0;
}