/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on November 4th, 2018, 2:15 AM
 * Purpose:  Circle ClassImplementation
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Circle.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const float PI = 3.14159;
//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Constant Variable
    
    //Declare all Variables Here
    float r;
    cout << "Enter the radius: ";
    cin >> r;
    
    Circle one(r, PI);
    //Input or initialize values Here

    //Process/Calculations Here
    
    //Output Located Here
    one.pCircle();
    //Exit
    
    return 0;
}