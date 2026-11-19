#include <iostream>
#include <sstream>
#include <string>
#include <iterator>

using namespace std;


template <typename Itr>
string to_string(Itr start, Itr end) {
    ostringstream oss;
    oss << "[ ";
    for (auto it = start; it != end; ++it) {
        oss << *it << " ";
    }
    oss << "]";
    return oss.str();
}


template <typename Itr, typename T>
int replace(Itr start, Itr end, const T& a, const T& b) {
    int count = 0;
    for (auto it = start; it != end; ++it) {
        if (*it == a) {
            *it = b;
            count++;
        }
    }
    return count;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    cout << "Original array: " << to_string(begin(arr), end(arr)) << endl;
    int replaced = replace(begin(arr), end(arr), 2, 6);
    cout << "Array after replacement: " << to_string(begin(arr), end(arr)) << endl;
    cout << "Number of elements replaced: " << replaced << endl;
    return 0;
}