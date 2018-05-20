//
// Created by Seyedhooman Hesamyan on 4/10/18.
//

#ifndef ASSIGN10_DATE_H
#define ASSIGN10_DATE_H
#include <string>
#include <vector>
using namespace std;
typedef int var;

class Date {
public:
    Date(); // Constructor of the Date class
    Date(var, var, var);
    Date(var, string, var);
    Date(const Date& );
    ~Date();
    Date operator+ (int);
    void operator+= (int);
    void operator+= (Date);
    string get_formatted_date(char format = 'y'); // Delivers a string of date in several formats and by default is what is mentioned in the exercise
    bool is_earlier(); // Returns an output to indicate whether the initialized date is earlier than current date or not
    int age(); // Returns age of object in year

protected:
    vector <string> monthList = {"January", "February", "March", "April", "May", "June", "July",
                                 "August", "September", "October", "November", "December"};

    void current(Date &);
    void month_fix(string &);
    string to_lower(string &);
private:
    var _day;
    var _month;
    var _year;
};


#endif //ASSIGN10_DATE_H
