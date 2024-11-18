//
// Created by Sydney Clements on 10/2/24.
//
#include "Date.h"
using namespace std;

bool test_increment_day();
bool test_increment_month();
bool test_increment_year();
bool test_multi_increment();
bool test_check_leapyear();
bool test_find_day_of_week();
bool test_string_to_month();
bool test_string_to_day();
bool test_date_to_int();

int main() {
    if(test_increment_day()) {
        cout << "Passed increment day test cases" << endl;
    }
    if(test_increment_month()) {
        cout << "Passed increment month test cases" << endl;
    }
    if(test_increment_year()) {
        cout << "Passed increment year test cases" << endl;
    }
    if(test_multi_increment()) {
        cout << "Passed multi increment test cases" << endl;
    }
    if(test_check_leapyear()) {
        cout << "Passed check leapyear test cases" << endl;
    }
    if(test_find_day_of_week()) {
        cout << "Passed find day of week test cases" << endl;
    }
    if(test_string_to_month()) {
        cout << "Passed string to month test cases" << endl;
    }
    if(test_string_to_day()) {
        cout << "Passed string to day test cases" << endl;
    }
    if(test_date_to_int()) {
        cout << "Passed date to int test cases" << endl;
    }
    return 0;
}

bool test_increment_day() {
    bool passed = true;
    Date date = Date(12, "oct", 2003);
    date.incrementDay();
    if(date.getDay() != 13) {
        passed = false;
        cout << "FAILED increment day test" << endl;
    }
    return passed;
}

bool test_increment_month() {
    bool passed = true;
    Date date = Date(12, "oct", 2003);
    date.incrementMonth();
    if(date.getMonth() != Month::November) {
        passed = false;
        cout << "FAILED increment month test" << endl;
    }
    return passed;
}

bool test_increment_year() {
    bool passed = true;
    Date date = Date(12, "oct", 2003);
    date.incrementYear();
    if(date.getYear() != 2004) {
        passed = false;
        cout << "FAILED increment year test" << endl;
    }
    return passed;
}

bool test_multi_increment() {
    bool passed = true;
    Date date = Date(12, "oct", 2003);
    date.multiIncrementDay(3);
    if(date.getDay() != 15) {
        passed = false;
        cout << "FAILED multi increment day test" << endl;
    }
    return passed;
}

bool test_check_leapyear() {
    bool passed = true;
    Date date1 = Date(12, "oct", 2020);
    bool leap1 = date1.checkLeapYear();
    Date date2 = Date(12, "oct", 2021);
    bool leap2 = date2.checkLeapYear();
    if(!leap1) {
        passed = false;
        cout << "FAILED leap year test 1" << endl;
    }
    if(leap2) {
        passed = false;
        cout << "FAILED leap year test 2" << endl;
    }
    return passed;
}

bool test_find_day_of_week() {
    bool passed = true;
    Date date = Date(16, "oct", 2023);
    date.findDayOfWeek();
    if(date.getDayOfWeek() != DayOfWeek::Monday) {
        passed = false;
        cout << "FAILED find day of week test" << endl;
    }
    return passed;
}

bool test_string_to_month() {
    bool passed = true;
    Date date = Date(12, "Jan", 2003);
    if(date.stringToMonth("Jan") != Month::January) {
        passed = false;
        cout << "FAILED string to month test" << endl;
    }
    return passed;
}

bool test_string_to_day() {
    bool passed = true;
    Date date = Date(12, "Jan", 2003);
    if(date.stringToDayOfWeek("sun") != DayOfWeek::Sunday) {
        passed = false;
        cout << "FAILED string to day of week test" << endl;
    }
    return passed;
}

bool test_date_to_int() {
    bool passed = true;
    Date date = Date(8, "Feb", 2023);
    int cDate = date.dateToInt();
    if(cDate != 39) {
        passed = false;
        cout << "FAILED date to int test" << endl;
    }
    return passed;
}