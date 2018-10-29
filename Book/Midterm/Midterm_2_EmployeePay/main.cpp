/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on October 24th, 2018 4:15pm
 * Purpose:  Midterm Q2
 */

/*2)  Develop an application using an array of structures that will 
determine the gross pay for any number of employees input. The company pays 
"straight-time" for the first 40 hours worked, double time for 
all hours worked in excess of 40 hours but less than 50 hours, 
and triple time for any hours worked over 50 hours.

The program should be able to loop and input the employee's name, 
hours worked, and the rate of pay.  Once this has been done then output
this information including the gross pay in the form of a paycheck.
The process starts all over 
again until you input an invalid rate of pay or hours worked.  This
means a negative rate of pay or negative number of hours worked is
not acceptable.

Print it out like an actual paycheck with English
language representing the check amount.
Print out like a company Paycheck with format:
     Company
     Address
     Name:	Amount: numerical
     Amount:    English of numerical value
     Signature Line:
*/
// System Libraries Here
#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

// User Libraries Here
#include "EmpStruct.h"

// Global Constants Only, No Global Variables
// Like PI, e, Gravity, or conversions

// Function Prototypes Here
int paycalc(int, int);
void chprint(Emp);
// Program Execution Begins Here
int main(int argc, char** argv) {
    // Declare all Variables Here
    int numemp;
    Emp * Team;
    
    // Input or initialize values Here
    cout << "How many employees? : ";
    cin >> numemp;
    cin.ignore();
    Team = new Emp [numemp];
    for(int i = 0; i < numemp; i++){
        cout << "Enter the name of employee #" << i+1 << " :";
        getline(cin,Team[i].name, '\n');
        cout << "Hours worked : ";
        cin >> Team[i].hrswrkd;
        cout << "Pay rate in dollars per hour :";
        cin >> Team[i].payrate;
        cin.ignore();
        Team[i].pay = paycalc(Team[i].hrswrkd, Team[i].payrate);

    }
    for(int i = 0; i < numemp; i++){
        chprint(Team[i]);
    }
    // Process/Calculations Here
    
    // Output Located Here
    

    // Exit
    return 0;
}
int paycalc(int hours, int rate){
    int pay = 0;
    int wrknum;
    if(hours > 40){
        pay = 40 * rate;
        hours -= 40;
        if(hours > 10){
            wrknum = 10 * (rate * 2);
            pay += wrknum;
            hours-=10;
            wrknum = hours * (rate * 3);
            pay += wrknum;
        }
        else{
            wrknum = hours * (rate * 2);
            pay += wrknum;
        }
    }
    else{
        pay = hours * rate;
    }
    return pay;
}
void chprint(Emp minion){
    int width = 35;
    cout << "Company : Mediocre Coding LLC" << endl;
    cout << "Address : 1234 Dropout st." << endl;
    cout << "Name: " << minion.name << setw(width) << "Amount: $" << minion.pay << endl;
    cout << "Signature X______________________________" << endl << endl << endl;
}