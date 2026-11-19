#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class Date {
public:

    Date();
    Date(int year, int month, int day);
    Date(const std::string& year_month_day);

    int get_year() const;
    int get_month() const;
    int get_day() const;

    bool is_valid() const; 
    void write() const;    
private:
    // attributes
    int year;
    int month;
    int day;

    static int num_days(int year, int month);
};

Date::Date() : year(1), month(1), day(1) {}


Date::Date(int year, int month, int day) : year(year), month(month), day(day) {
    if (!is_valid()) {
        year = month = day = 0;
    }
}

Date::Date(const std::string& year_month_day) {
    std::istringstream iss(year_month_day);
    char separator;
    iss >> year >> separator >> month >> separator >> day;

    if (!is_valid()) {
        year = month = day = 0;
    }
}

int Date::get_year() const { return year; }
int Date::get_month() const { return month; }
int Date::get_day() const { return day; }

int Date::num_days(int year, int month) {
    static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int num_days = days_in_month[month - 1];
    if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
        num_days = 29; 
    }
    return num_days;
}

bool Date::is_valid() const {
    return year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= num_days(year, month);
}

void Date::write() const {
    std::cout << std::setfill('0') << std::setw(4) << year << "/"
              << std::setw(2) << month << "/" << std::setw(2) << day;
}