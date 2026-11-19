
#ifndef DATE1_CPP
#define DATE1_CPP

#include "Date1.h"
#include <iostream>
using namespace std;

Date::Date() : year(1), month(1), day(1) {}

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

int Date::get_year() const { return year; }
int Date::get_month() const { return month; }
int Date::get_day() const { return day; }

void Date::write() const {
    cout << year << "/" << month << "/" << day;
}

bool is_before(const Date& date1, const Date& date2) {
    if (date1.get_year() < date2.get_year()) return true;
    if (date1.get_year() > date2.get_year()) return false;
    if (date1.get_month() < date2.get_month()) return true;
    if (date1.get_month() > date2.get_month()) return false;
    return date1.get_day() < date2.get_day();
}

#endif
