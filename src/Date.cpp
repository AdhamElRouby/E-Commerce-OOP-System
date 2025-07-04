#include "Date.h"
#include <iostream>
#include <ctime>

Date::Date() {
    const time_t now = time(nullptr);
    const tm* timeinfo = localtime(&now);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    year = timeinfo->tm_year + 1900;
}

Date::Date(const int day, const int month, const int year) : day(day), month(month), year(year) {}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(const int day) {
    this->day = day;
}

void Date::setMonth(const int month) {
    this->month = month;
}

void Date::setYear(const int year) {
    this->year = year;
}

void Date::toString() const {
    std::cout << day << "/" << month << "/" << year << std::endl;
}