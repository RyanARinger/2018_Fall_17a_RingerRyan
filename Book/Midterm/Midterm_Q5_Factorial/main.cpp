/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 19, 2016, 9:07 AM
 * Purpose:  Hello World Template
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int FACT = 30;
    
    unsigned int a = FACT;
    unsigned int str = FACT -1;
    
    //Input or initialize values Here
    for(int i = 0; i<FACT; i++){
        if(str>0){
            a *= str;
            str--;
        }
    }
    //Process/Calculations Here

    //Output Located Here
    cout << a;
    //Exit
    return 0;
}

