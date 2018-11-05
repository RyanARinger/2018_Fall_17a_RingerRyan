/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on November 2nd, 2018 10:08 PM
 * Purpose:  Date Class Implementation
 */

// System Libraries Here
#include <iostream>
using namespace std;

// User Libraries Here
#include "DateClass.h"

// Global Constants Only, No Global Variables
// Like PI, e, Gravity, or conversions

// Function Prototypes Here

// Program Execution Begins Here
int main(int argc, char** argv) {
    // Declare all Variables Here
    int m, d, y;
    Date Today;
    // Input or initialize values Here
    do{
        cout << "What is the month (two digit)? :";
        cin >> m;
        if(m>12 || m<1){
            cout << "ERROR. Month must be between 1 and 12" << endl;
        }
    }while(m>12 || m<1);
    
    do{
        cout << "The day (Two Digit)? ";
        cin >> d;
        if(d>31 || d<1){
            cout << "ERROR. Day must be between 1 and 31" << endl;
        }
    }while(d>31 || d<1);
    
    cout << "The year (four digit)? ";
    cin >> y;
    
    Today.setMnth(m);
    Today.setDay(d);
    Today.setYear(y);
    // Process/Calculations Here
    
    // Output Located Here
    Today.prnDate();    

    // Exit
    return 0;
}
