//
// Created by Seyedhooman Hesamyan on 4/26/18.
//

#ifndef HMW3_PERSON_H
#define HMW3_PERSON_H
#include <cctype>
#include "Date.h"

class Person {
    /**
     * Super class of Student class which has following members
     */
    protected:
        string _first_name;
        string _last_name;
        Date _birthdate; // It is also an object of the class Date

};


#endif //HMW3_PERSON_H
