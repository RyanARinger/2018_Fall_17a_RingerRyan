/* 
 * File:   Date Class
 * Author: Ryan Ringer
 * Purpose: Date Class Initialization
 * Created on November 2, 2018, 10:25 PM
 */
#include <iostream>

using namespace std;

#include "DateClass.h"
    int month;
    int day;
    int year;

void Date::prnDate(){
    const int nMonth = 12;
    int m, d, y;
    std::string months [nMonth] = {"January", "February", "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December"};
    m = Date::getMnth();
    d = Date::getDay();
    y = Date::getYear();
    cout << m << "/" << d << "/" << y << endl;
    cout << months[m-1] << " " << d << ", " << y << endl;
    cout << d << " " << months[m-1] << " " << y;
}
        

