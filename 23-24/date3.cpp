#include <iostream>
#include <string>

class Date {
public:
    // Constructors
    Date();
    Date(int year, int month, int day);
    Date(const std::string& year_month_day);
    
    // Accessors
    int get_year() const;
    int get_month() const;
    int get_day() const;
    
    // Other methods
    bool is_valid() const;
    void write() const;

private:
    // Compute the number of days of a month
    static int num_days(int year, int month);
    
    // Attribute
    std::string yyyymmdd;
};

// Default constructor
Date::Date() : yyyymmdd("00000101") {}

// Constructor with year, month, and day
Date::Date(int year, int month, int day) {
    yyyymmdd = std::to_string(year * 10000 + month * 100 + day);
}

// Constructor with string in "yyyymmdd" format
Date::Date(const std::string& year_month_day) : yyyymmdd(year_month_day) {}

// Accessor for year
int Date::get_year() const {
    return std::stoi(yyyymmdd.substr(0, 4));
}

// Accessor for month
int Date::get_month() const {
    return std::stoi(yyyymmdd.substr(4, 2));
}

// Accessor for day
int Date::get_day() const {
    return std::stoi(yyyymmdd.substr(6, 2));
}

// Check if the date is valid
bool Date::is_valid() const {
    int year = get_year();
    int month = get_month();
    int day = get_day();
    
    if (year < 1 || year > 9999 || month < 1 || month > 12 || day < 1 || day > num_days(year, month)) {
        return false;
    }
    return true;
}

// Write the date in "yyyy/mm/dd" format
void Date::write() const {
    std::cout << get_year() << "/" << get_month() << "/" << get_day();
}

// Compute the number of days in a month
int Date::num_days(int year, int month) {
    const int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = days_in_month[month];
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        days = 29;
    }
    return days;
}