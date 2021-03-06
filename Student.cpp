//
// Created by Seyedhooman Hesamyan on 4/22/18.
//
#include <iostream>
#include "Student.h"

using namespace std;

long int Student::id_counter = 1111; // The static member, the most important thing, which is the head-point of this homework

Student::Student() {
    /**
     * The dummy constructor, setting all default information, (Mine information!)
     */

    _first_name = "HOOMAN";
    _last_name = "HESAMYAN";
    _faculty = "CIS";
    _birthdate = Date(22, 5, 1981);
    _ID = id_generator();
};

Student::Student(string first_name, string last_name, string faculty) {
    /**
     * The parameterised constructor, setting first name, last name, and faculty name
     * and the most important setting is to assigning unique ID to it
     * and also default birthdate information (Mine birthdate!)
     */
    this->_first_name = to_upper(first_name);
    this->_last_name = to_upper(last_name);
    this->_birthdate = Date(22, 5, 1981);
    this->_faculty = to_upper(faculty);
    this->_ID = id_generator();
};

Student::Student(Student &person) {
    /**
     * The copy constructor, just copying the faculty name and assigning a unique ID
     */
    this->_faculty = person._faculty;
    this->_ID = id_generator();
};

void Student::set_name(string first_name) {
    /**
     * This function serves as a first name setter
     */
    this->_first_name = to_upper(first_name);
};

void Student::set_name(string first_name, string last_name) {
    /**
    * This function serves as a full-name setter, first name and also last name
    */
    this->_first_name = to_upper(first_name);
    this->_last_name = to_upper(last_name);
};

void Student::set_birthday(int day, int month, int year) {
    /**
    * This function serves as a birthdate setter, month is a integer type
    */
    this->_birthdate = Date(day, month, year);
};

void Student::set_birthday(int day, string month, int year) {
    /**
    * This function serves as a birthdate setter, month is a string type
    */
    this->_birthdate = Date(day, month, year);
}

void Student::set_faculty(string faculty) {
    /**
     * This function serves as a faculty setter
     */
    this->_faculty = to_upper(faculty);
};

string Student::get_first_name() {
    /**
     * This function simply serves as a first name getter
     */
    return _first_name;
};

string Student::get_last_name() {
    /**
     * This function simply serves as a last name getter
     */
    return _last_name;
};

Date Student::get_birthdate() {
    /**
     * This function simply serves as a birthdate getter (birthdate is also an object of class Date)
     */
    return _birthdate;
};

int Student::get_age() {
    /**
     * This function simply serves as a age getter
     */
    return _birthdate.age();
};

string Student::get_faculty() {
    /**
     * This function simply serves as a faculty getter
     */
    return _faculty;
};

string Student::get_ID() {
    /**
     * This function simply serves as a ID getter
     */
    return _ID;
};

string Student:: id_generator() {
    /**
     * This function serves as a ID generator and uses a static member to guarantee producing a unique ID
     */
    auto *output = new string;
    *output = "AUA_" + _faculty + "_"+ to_string(id_counter++);
    return *output;
};

string Student::to_upper(string & text) {
    /**
     * This function serves as a converter to guarantee that its output is always in upper-case format
     */
    char character [256];
    string output;
    for (int i = 0; i < 256; ++i) {
        character[i] = text[i];
    };
    for (char &j : character) {
        if (j != ' ') {
            j = static_cast<char>(toupper(j));
        };
    };
    int k = 0;
    while (character[k] != ' ') {
        output += character[k++];
    };
    return output;
}


