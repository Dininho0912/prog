#include "Book.h"
#include <fstream>
#include <sstream>
using namespace std;

void Book::build_index(const set<string>& words) {
    ifstream file(filename_);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename_ << endl;
        return;
    }

    string line;
    int page_number = 1;
    set<string> word_set(words.begin(), words.end());

    while (getline(file, line)) {
        stringstream page_content;
        while (line != "<PAGE>") {
            page_content << line << " ";
            if (!getline(file, line)) {
                break;
            }
        }

        string word;
        while (page_content >> word) {
            for (auto& c : word) {
                c = tolower(c);
            }

            if (word_set.find(word) != word_set.end()) {
                index_[word].insert(page_number);
            }
        }

        page_number++;
    }

    file.close();
}