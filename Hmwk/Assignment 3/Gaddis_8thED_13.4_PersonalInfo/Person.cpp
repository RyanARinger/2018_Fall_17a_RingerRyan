/* 
 * File:   PersonClass.h
 * Author: Ryan Ringer
 * Purpose: Person Class Initialization
 * Created on November 3, 2018, 11:32 AM
 */
#include <iostream>
using namespace std;
#include "PersonClass.h"
    
    std::string name;
    std::string addy;
    int age;
    std::string phone;

    void Person::prnInfo(){
        std::string name = Person::getName();
        std::string address = Person::getAddy();
        std::string phone = Person::getPhne();
        int age = Person::getAge();
        
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Age: " << age << endl;
        cout << "Phone #: " << phone << endl;
    }