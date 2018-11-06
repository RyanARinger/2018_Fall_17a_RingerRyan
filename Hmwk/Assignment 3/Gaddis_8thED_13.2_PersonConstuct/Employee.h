/* 
 * File:   Employee.h
 * Author: Ryan Ringer
 * Purpose: Employee Class Definition
 * Created on November 4, 2018, 2:03 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Empl{
    private:
        string name;
        int idNum;
        string dept;
        string jobTtle;
    public:
        Empl();
        Empl(string, int, string, string);
        Empl(string, int);
        void setName(string n) { name = n; }
        void setId (int i) { idNum = i; }
        void setDept (string d) { dept = d; }
        void setJob (string j) { jobTtle = j; }
        string getName() const { return name; }
        int getId () const { return idNum; }
        string getDept () const { return dept; }
        string getJob () const { return jobTtle; }
        void prnEmp ();
};


#endif /* EMPLOYEE_H */

