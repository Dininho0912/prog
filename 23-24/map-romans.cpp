#include <string>
#include <vector>
#include <utility>

using namespace std;

unsigned roman_to_arab(const string& roman) {
    vector<pair<char, unsigned>> roman_to_int = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    unsigned result = 0;

    for (size_t i = 0; i < roman.size(); ++i) {
        unsigned value = 0;
        for (const auto& pair : roman_to_int) {
            if (pair.first == roman[i]) {
                value = pair.second;
                break;
            }
        }

        if (i + 1 < roman.size() &&
            value < roman_to_int[i + 1].second) {
            result -= value;
        } else {
            result += value;
        }
    }

    return result;
}
