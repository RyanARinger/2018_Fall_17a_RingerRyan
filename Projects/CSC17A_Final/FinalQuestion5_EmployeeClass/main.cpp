/* 
 * File:   
 * Author: Ryan Ringer
 *
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

#include "Employee.h"
//Execution Begins Here


int main(int argc, char** argv) {
    
    // i was getting some warnings because i was sending string literals instead of
    // char[] so i made these to mitigate the warnings
    char name1[5]  = "Mark";
    char name2[5]  = "Mary";
    char title1[5]  = "Boss";
    char title2[4] = "VP";
    
    Employee Mark(name1,title1,215.50); 
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.calculatePay(Mark.setHourlyRate(20.0),
                      Mark.setHoursWorked(25));
    Mark.toString();
    Mark.calculatePay(Mark.setHourlyRate(40.0),
                      Mark.setHoursWorked(25));
    Mark.toString();
    Mark.calculatePay(Mark.setHourlyRate(60.0),
                      Mark.setHoursWorked(25));
    Mark.toString();

    Employee Mary(name2,title2,50.0);
    Mary.toString();
    Mary.calculatePay(Mary.setHourlyRate(50.0),
                      Mary.setHoursWorked(40));
    Mary.toString();
    Mary.calculatePay(Mary.setHourlyRate(50.0),
                      Mary.setHoursWorked(50));
    Mary.toString();
    Mary.calculatePay(Mary.setHourlyRate(50.0),
                      Mary.setHoursWorked(60));
    Mary.toString();
    return 0;
}
