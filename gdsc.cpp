#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

string getDateFromDayOfYear(int dayOfYear, int year) {
    vector<int> daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    int month = 0;
    while (dayOfYear > daysInMonth[month]) {
        dayOfYear -= daysInMonth[month];
        month++;
    }

    // Adding 1 to month as vector index starts from 0 (January) to 11 (December)
    ostringstream date;
    date << std::setw(2) << std::setfill('0') << dayOfYear << "/"
         << std::setw(2) << std::setfill('0') << (month + 1) << "/"
         << year;

    return date.str();
}

int getWeekOfYear(int dayOfYear) {
    return (dayOfYear - 1) / 7 + 1;
}

int main() {
    int dayOfYear, year;
    cout << "Enter the day of the year: ";
    cin >> dayOfYear;
    cout << "Enter the year: ";
    cin >> year;

    bool leapYear = isLeapYear(year);

    if (dayOfYear < 1 || dayOfYear > (leapYear ? 366 : 365)) {
        std::cerr << "Invalid day of the year for the given year." << std::endl;
        return 1;
    }

    std::string date = getDateFromDayOfYear(dayOfYear, year);
    int weekOfYear = getWeekOfYear(dayOfYear);

    cout << "The date is: " << date << std::endl;
    cout << "Week of the year: " << weekOfYear << std::endl;
    cout << "Leap year: " << (leapYear ? "true" : "false") << std::endl;

    return 0;
}
