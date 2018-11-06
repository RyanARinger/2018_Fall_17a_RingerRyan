/* 
 * File:   Employee.h
 * Author: Ryan Ringer
 * Purpose: Employee Class Definition
 * Created on November 4, 2018, 2:27 PM
 */
#include <iostream>
#include <string>
using namespace std;

#include "Employee.h"

Empl::Empl(){
    name = "";
    idNum = 0;
    dept = "";
    jobTtle = "";
}
Empl::Empl(string n, int i, string d, string j){
    
    Empl::setName(n);
    Empl::setId(i);
    Empl::setDept(d);
    Empl::setJob(j);
    
}
Empl::Empl(string n, int i){
    Empl::setName(n);
    Empl::setId(i);
    dept = "";
    jobTtle = "";
    
}
void Empl::prnEmp(){
    cout << endl << endl;
    cout << "Name: " << name << endl;
    cout << "ID: " << idNum << endl;
    cout << "Department: " << dept << endl;
    cout << "Position: " << jobTtle << endl;
    cout << endl << endl;
}