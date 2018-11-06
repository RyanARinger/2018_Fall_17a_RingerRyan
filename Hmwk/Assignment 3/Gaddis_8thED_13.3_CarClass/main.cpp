/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on November 4th, 2018, 2:15 AM
 * Purpose:  File Head
 */

//System Libraries Here
#include <iostream>
#include <string>
using namespace std;

//User Libraries Here
#include "Car.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Constant Variable
    const int NAC = 5;
    //Declare all Variables Here
    int mo = 2014;
    string ma = "R8";
    Car audi( mo, ma);    
    //Input or initialize values Here
    
    //Process/Calculations Here
    for(int i = 0; i<NAC; i++){
        audi.accelerate();
        audi.prnSpd();
    }
    cout << endl << endl;
    for(int i = 0; i<NAC; i++){
        audi.brake();
        audi.prnSpd();
    }
    //Output Located Here
    
    //Exit
    
    return 0;
}