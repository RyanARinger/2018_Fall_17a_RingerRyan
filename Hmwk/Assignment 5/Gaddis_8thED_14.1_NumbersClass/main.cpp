/* 
 * File:   main.cpp
 * Author: Ryan Ringer 
 * Purpose: Number Class Implementation
 * Created on November 11, 2018, 4:41 PM
 */

// System Libraries Here
#include <iostream>
using namespace std;

// User Libraries Here
#include "Number.h"
// Global Constants Only, No Global Variables
// Like PI, e, Gravity, or conversions

// Function Prototypes Here

// Program Execution Begins Here

int main(int argc, char** argv) {
    // Declare all Variables Here
    int input;
    cout << "Enter a number (min -9999/ max 9999): ";
    cin >> input;

    Num number(input);
    // Input or initialize values Here
    
    // Process/Calculations Here

    // Output Located Here
    
    number.prnNum();

    // Exit
    return 0;
}