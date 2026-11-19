#include <iostream>
#include <iomanip>
using namespace std;

class Date {
public:
    Date(int year = 1, int month = 1, int day = 1) : year_(year), month_(month), day_(day) {}

    int getYear() const { return year_; }
    int getMonth() const { return month_; }
    int getDay() const { return day_; }

    bool operator<(const Date& other) const {
        if (year_ != other.year_) return year_ < other.year_;
        if (month_ != other.month_) return month_ < other.month_;
        return day_ < other.day_;
    }

private:
    int year_, month_, day_;
};

ostream& operator<<(ostream& os, const Date& date) {
    os << setw(4) << setfill('0') << date.getYear() << '/'
       << setw(2) << setfill('0') << date.getMonth() << '/'
       << setw(2) << setfill('0') << date.getDay();
    return os;
}