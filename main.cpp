#include <iostream>
#include "Date.h"
#include "Student.h"
using namespace std;

int main() {

    Date test(10, 5, 2018);
    cout << test.get_formatted_date() << endl;
    test = test + 6;
    cout << test.get_formatted_date() << endl;
    test += 3;
    cout << test.get_formatted_date() << endl;
    test += test;
    cout << test.get_formatted_date() << endl;

//    cout << endl << "*****************************************************************************************************" << endl;
//
//    Student hooman("Hooman", "Hesamyan", "Mch"), amir("Amir", "Hesamian", "CIS"); // Declaring two objects with parameterised Constructor
//
//    hooman.set_birthday(22, "may", 1981); // Setting the birth information
//
//    cout << "\nHooman's information:" << endl; // Extracting and printing the following information:
//    cout << "\nID: " << hooman.get_ID() << endl;
//    cout << "\nAge: " << hooman.get_age() << endl;
//    cout << "\nFaculty: " << hooman.get_faculty() << endl;
//    cout << "\nFirst name: " << hooman.get_first_name() << endl;
//    cout << "\nLast name: " << hooman.get_last_name() << endl;
//    cout << "\n" << hooman.get_birthdate().get_formatted_date() << endl;
//
//    cout << endl << "*****************************************************************************************************" << endl;
//
//    amir.set_birthday(5, 2, 1993); // Setting the birth information
//
//    cout << "\nAmir's information:" << endl; // Extracting and printing the following information:
//    cout << "\nID: " << amir.get_ID() << endl;
//    cout << "\nAge: " << amir.get_age() << endl;
//    cout << "\nFaculty: " << amir.get_faculty() << endl;
//    cout << "\nFirst name: " << amir.get_first_name() << endl;
//    cout << "\nLast name: " << amir.get_last_name() << endl;
//    cout << "\n" << amir.get_birthdate().get_formatted_date() << endl;
//
//    cout << endl << "*****************************************************************************************************" << endl;
//
//    Student shima; // Declaring an object with dummy constructor
//    shima.set_birthday(3, "mArcH", 1991); // Setting the birth information, it is not case sensitive
//    shima.set_name("Shima", "Shahriary"); // Setting name information
//    shima.set_faculty("GEO"); // Setting faculty
//
//    cout << "\nShima's information:" << endl; // Extracting and printing the following information:
//    cout << "\nID: " << shima.get_ID() << endl;
//    cout << "\nAge: " << shima.get_age() << endl;
//    cout << "\nFaculty: " << shima.get_faculty() << endl;
//    cout << "\nFirst name: " << shima.get_first_name() << endl;
//    cout << "\nLast name: " << shima.get_last_name() << endl;
//    cout << "\n" << shima.get_birthdate().get_formatted_date() << endl;
//
//    cout << endl << "*****************************************************************************************************" << endl;
//
//    Student vihan(shima); // Declaring an object with copy constructor
//    vihan.set_name("David", "Hesamyan"); // Setting name information
//    vihan.set_name("Vihan"); // Overriding first-name
//    vihan.set_birthday(20, "march", 2016); // Setting the birth information, it is not case sensitive
//
//    cout << "\nVihan's information:" << endl; // Extracting and printing the following information:
//    cout << "\nID: " << vihan.get_ID() << endl;
//    cout << "\nAge: " << vihan.get_age() << endl;
//    cout << "\nFaculty: " << vihan.get_faculty() << endl;
//    cout << "\nFirst name: " << vihan.get_first_name() << endl;
//    cout << "\nLast name: " << vihan.get_last_name() << endl;
//    cout << "\n" << vihan.get_birthdate().get_formatted_date() << endl;
//
//    cout << endl << "*****************************************************************************************************" << endl;
//    return 0;
}