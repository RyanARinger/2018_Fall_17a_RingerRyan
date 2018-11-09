/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Purpose: Population Class Implementation
 * Created on November 8, 2018, 5:00 PM
 */


//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Pop.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here

int main(int argc, char** argv) {
    //Constant Variable

    //Declare all Variables Here
    float p, b, d;
    cout << " Enter the population size: ";
    cin >> p;
    cout << "Enter the number of Births: ";
    cin >> b;
    cout << "Enter the number of Deaths: ";
    cin >> d;
    Pop group(p, b, d);
    //Input or initialize values Here

    //Process/Calculations Here

    //Output Located Here

    //Exit

    return 0;
}

