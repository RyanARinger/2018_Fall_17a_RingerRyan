/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on November 19, 2018, 1:07 PM
 * Purpose:  Stuff from lecture 11/19/18
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "SimpleVector.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    // Constant Variables for main
    const int SZ = 100;
    
    //Declare all Variables Here
    SimpleVector<float> x(SZ);
    
    //Input or initialize values Here
    
    for(int i = 0; i < SZ; i++){
        x[i] = i+1;
    }
    for(int i = 0; i < SZ; i++){
        cout << x[i] << endl;
    }
    //Process/Calculations Here
    
    //Output Located Here
    
    //Exit
    return 0;
}

