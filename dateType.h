#pragma once
#include <iostream>

using namespace std;

class dateType {
private:
    int month;
    int day;
    int year;

    // Checks if a year is a leap year.
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }

    // Returns the number of days in a month
    int getDaysInMonth(int month, int year) const {
        switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
        }
    }

public:
    // Default constructor
    dateType() : month(1), day(1), year(1900) {}

    // Parameterized constructor
    dateType(int m, int d, int y) {
        setDate(m, d, y);
    }

    // Set the date with validation
    void setDate(int m, int d, int y) {
        if (y >= 1900) {
            year = y;
        }
        else {
            cout << "Date invalid, setting to 1/1/1900" << endl;
            year = 1900;
        }

        if (m >= 1 && m <= 12) {
            month = m;
        }
        else {
            cout << "Date invalid, setting to 1/1/1900" << endl;
            month = 1;
        }

        int daysInMonth = getDaysInMonth(month, year);
        if (d >= 1 && d <= daysInMonth) {
            day = d;
        }
        else {
            cout << "Date invalid, setting to 1/1/1900" << endl;
            day = 1;
        }
    }

    // Print the date in the format MM-DD-YYYY
    void print() const {
        cout << month << "-" << day << "-" << year << endl;
    }
};

