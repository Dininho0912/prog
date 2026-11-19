#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

string to_lower(const std::string& str) {
    string lower_str = str;
    transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
    return lower_str;
}

void count_words(const std::string& str, std::map<std::string, size_t>& count) {
    istringstream stream(to_lower(str));
    string word;
    while (stream >> word) {
        // Remove punctuation from the word
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        ++count[word];
    }
}

void show_map(const std::map<std::string, size_t>& count) {
    cout << "[ ";
    for (const auto& e : count) {
        cout << e.first << ":" << e.second << ' ';
    }
    cout << "]\n";
}