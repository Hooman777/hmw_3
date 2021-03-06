//
// Created by Seyedhooman Hesamyan on 4/10/18.
//

#include "Date.h"
#include <iostream>
using namespace std;
typedef int var;

Date::Date() { // Dummy constructor
    /**
     * The constructor of Date class
     * initializes the parameters to January first of 1900
     */
    Date::_day = 1;
    Date::_month = 1;
    Date::_year = 1970;
}

Date::Date(var day,var month, var year) {
    /**
     * Parameterised constructor, gives three integers respectively as day, month, and year
     */
    if (day < 1 || day > 31) {
        throw out_of_range ("Entered day is invalid!"); // In order to check the input
    } else {
        this -> _day = day;
    }
    if (month < 1 || month > 12) {
        throw out_of_range ("Entered month is invalid!"); // In order to check the input
    } else {
        this -> _month = month;
    }
    if (year < 1) {
        throw out_of_range ("Entered year is invalid!"); // In order to check the input
    } else {
        this -> _year = year;
    }
}

Date::Date(var day, string month, var year) {
    /**
     * Parameterised constructor, gives two integers and one string as the month name
     */
    if (day < 1 || day > 31) {
        throw out_of_range ("Entered day is invalid!"); // In order to check the input
    } else {
        this -> _day = day;
    }
    month_fix(month); // To re-format the month in accepted format
    for (int i = 0; i < 12; ++i) {
        if (monthList[i] == month) {
            this->_month = ++i;
            break;
        } else if (i == 11) throw out_of_range ("Entered month is invalid!"); // In order to check the input
    }
    if (year < 1) {
        throw out_of_range ("Entered year is invalid!"); // In order to check the input
    } else {
        this -> _year = year;
    }
}

Date::Date(const Date & date) { // Copy constructor
    _day = date._day;
    _month = date._month;
    _year = date._year;
}

Date::~Date() { // Destructor
    // cout << "\nDestructor has done!" << endl;
}

void Date::current(Date &date) {
    /**
     * To extract the current date by calculating passed milli-seconds from Epoch date 1970
     */
    long double tillNow = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    var _currYear;
    var _currMonth;
    var _currDay;
    _currYear = static_cast<int>(tillNow / (1000 * 3600 * 24 * 365.25) + 1970);
    _currMonth =  static_cast<int>((tillNow / (1000 * 3600 * 24 * 365.25) - (_currYear - 1970)) * 12 + 1);
    _currDay = static_cast<int>(((tillNow / (1000 * 3600 * 24 * 365.25) - (_currYear - 1970)) * 365) - (_currMonth - 1) * 30 + 1);
    date._year = _currYear;
    date._month = _currMonth;
    date._day = _currDay;
}

bool Date::is_earlier() {
    /**
     * To return a boolean variable to check the date if is earlier than present or not
     */
    auto *_currentDate = new Date; // It is a temporary Date object
    current(*_currentDate); // Assigning its values by current function 
    if (_year < (*_currentDate)._year) {
        delete _currentDate;
        return true;
    } else if (_year == (*_currentDate)._year && _month < (*_currentDate)._month) {
        delete _currentDate;
        return true;
    } else {
        delete _currentDate;
        return _year == (*_currentDate)._year && _month == (*_currentDate)._month && _day < (*_currentDate)._day;
    }

}

string Date::get_formatted_date(char format) {
    /**
     * To return a string to mention the initialized time based on the given flag as the format indicator
     */
    if (format == 'y' || format == 'Y') { // Default flag
        return to_string(_year) + ", " + monthList[_month - 1] + " - " + to_string(_day) ;
    }
    if (format == 'l' || format == 'L') { // Standard Little-Endian
        return to_string(_day) + ". " + monthList[_month - 1]+ ". " + to_string(_year);
    }
    if (format == 'b' || format == 'B') { // Standard Big-Endian
        return to_string(_year) + " - " + to_string(_month) + " - " + to_string(_day);
    }
    if (format == 'm' || format == 'M') { // Standard Middle-Endian
        return monthList[_month - 1]+ " " + to_string(_day) + ", " +  to_string(_year);
    }
    //return nullptr;
}

int Date::age() {
    /**
     * Returns the age in year based on the current date
     */
    var age = 0;
    auto *_currentDate = new Date; // It is a temporary Date object
    current(*_currentDate); // Assigning its values by current function
    if (is_earlier()) {
        age = (*_currentDate)._year - _year;
    } else {
        throw out_of_range("You have not been born yet!");
    }
    delete _currentDate;
    return age;
}

void Date::month_fix(string & month_name) {
    /**
     * To make the constructor not case sensitive about the string which is input as an argument
     */
    string output;
    auto first_letter = static_cast<char>(toupper(month_name[0]));
    month_name = first_letter + to_lower(month_name);
}

string Date::to_lower(string & text) {
    char character [256];
    string output;
    for (int i = 0; i < 256; ++i) {
        character[i] = text[i];
    };



    for (char &j : character) {
        if (j != ' ') {
            j = static_cast<char>(tolower(j));
        };
    };
    int k = 1;
    while (character[k] != ' ') {
        output += character[k++];
    };
    return output;
}

Date Date::operator+(int extraDay) {
    Date output(_day + extraDay,_month, _year);
    return output;
}

void Date::operator+=(int extraDay) {
    _day += extraDay;
}

void Date::operator+=(Date date) {
    _day += date._day;
}



