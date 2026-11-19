#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void print_grades(const map<string, list<int>>&grades){
    vector<pair<string, double>> student_avg;

    for (const auto& entry : grades){
        const string& student = entry.first;
        const list<int> &student_grades = entry.second;

        double sum = 0.0;
        for (int grade : student_grades) sum += grade;

        double average = student_grades.empty() ? 0.0 : sum / student_grades.size();
        student_avg.push_back({student, average});
    }

    sort(student_avg.begin(), student_avg.end(),
         [](const pair<string, double>& a, const pair<string, double>& b) {
             return a.second > b.second;
         });

    cout << fixed << setprecision(2);

    double sum_of_averages = 0.0;
    for (const auto& entry : student_avg) {
        cout << entry.first << " " << entry.second << endl;
        sum_of_averages += entry.second;
    }

    if (!student_avg.empty()) {
        double overall_average = sum_of_averages / student_avg.size();
        cout << overall_average << endl;
    } else {
        cout << "0.00" << endl;
    }
}