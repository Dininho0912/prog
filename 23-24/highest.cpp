#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

string student_highest_avg(map<string, list<int>> m) {
    string highest_avg_student;
    double highest_avg = -1.0;

    for (const auto& pair : m) {
        const string& student = pair.first;
        const list<int>& grades = pair.second;

        double sum = 0.0;
        for (int grade : grades) {
            sum += grade;
        }

        double avg = sum / grades.size();

        if (avg > highest_avg) {
            highest_avg = avg;
            highest_avg_student = student;
        }
    }

    return highest_avg_student;
}