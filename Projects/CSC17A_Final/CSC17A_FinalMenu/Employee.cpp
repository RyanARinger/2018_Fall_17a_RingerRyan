/* 
 * File:   Employee.cpp
 * Author: Ryan Ringer
 * Created on December 13, 2018 8:46 PM
 * Purpose: 
 */


#include <iostream>
#include <cstring>
using namespace std;
#include "Employee.h"

Employee::Employee(char name[], char title[], float payRate) {
    for (int i = 0; i < strlen(name); i++) {
        this->myName[i] = name[i];
    }    
    for (int i = 0; i < strlen(name); i++) {
        this->jobTitle[i] = title[i];
    }   
    setHourlyRate(payRate);   
    this->hoursWorked = 0;
    this->grossPay = 0;
    this->netPay = 0;
}

float Employee::tax(float gross) {
    float origTax, taxCurr, taxes;
    
    if (gross < 500) {
        return 0.1 * gross;
    } 
    
    else if (gross >= 500 && gross <= 1000) {
        origTax = 50;
        taxCurr = (gross - 500)*.20;
        taxes = origTax + taxCurr;
        
        return taxes;
    } 
    
    else {
        origTax = 150;
        taxCurr = (gross - 1000)*.30;
        taxes = origTax + taxCurr;
        
        return taxes;
    }
}

float Employee::calculatePay(float x, int y) {
    return getNetPay(getGrossPay(setHourlyRate(x), setHoursWorked(y))); 
}

float Employee::setHourlyRate(float rate) {
    if (rate > 0 && rate < 84) { 
        this->hourlyRate = rate;
    } else { 
        cout << "Unacceptable Hourly Rate" << std::endl;
        this->hourlyRate = 0;
    }
    return this->hourlyRate; 
}

int Employee::setHoursWorked(int hours) {
    if (hours > 0 && hours < 200) { 
        this->hoursWorked = hours;
    } else { 
        cout << "Unacceptable Hours Worked" << std::endl; 
        this->hoursWorked = 0;
    }
    return this->hoursWorked;
}

float Employee::getGrossPay(float rate, int hours) {
    int money = 0;        
    if (hours > 40) {
        money = rate*40;
        
        if (hours > 50) {
            money += rate*10*1.5; 
            
            hours -= 50;
            money += (hours*rate*2);
        }
        
        else {
            hours -= 40;
            money += (hours*rate*2);
        }
    }
    
    else {
        money = hours*rate;
    }
    
    this->grossPay = money;
    
    return this->grossPay;
}

float Employee::getNetPay(float) {
    this->netPay = this->grossPay - tax(this->grossPay);
    return this->netPay;
}

void Employee::toString() {
    cout << "Name = " << this->myName  <<  " Job Title = " << this->jobTitle << endl;
    cout << " Hourly Rate = " << this->hourlyRate << " Hours Worked = " << this->hoursWorked
         << " Gross Pay = " << this->grossPay << " Net Pay = " << this->netPay << endl;
}
