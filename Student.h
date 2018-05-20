//
// Created by Seyedhooman Hesamyan on 4/22/18.
//
#include <string>
#include <cctype>
#include "Date.h"
#include "Person.h"

using namespace std;

#ifndef HMW3_STUDENT_H
#define HMW3_STUDENT_H

class Student : public Person{ // Class Student inherits from the Person class publicly
    private:
        string _faculty;
        string _ID;

    protected:
        static long int id_counter; // Static member which is
        string id_generator(); // ID generator prototype
        string to_upper(string&);

    public:

        // Constructors prototypes:
        Student();
        Student(string, string, string);
        Student(Student&);

        // Setters prototypes:
        void set_name(string);
        void set_name(string, string);
        void set_birthday(int, int, int);
        void set_birthday(int, string, int);
        void set_faculty(string);

        // Getters prototypes:
        string get_first_name();
        string get_last_name();
        Date get_birthdate();
        int get_age();
        string get_faculty();
        string get_ID();

};


#endif //HMW3_STUDENT_H
