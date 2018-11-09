/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on November 6, 2018, 11:35 AM
 * Purpose: Test Scores Class Implementation
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Scores.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE = 3;
    int score[SIZE];
    for(int i=0; i<SIZE; i++){
        cout << "Enter score #" << i+1 << ": ";
        cin >> score[i];
    }
    Scores clas(score[0], score[1], score[2]);
    
    //Input or initialize values Here
    
    //Process/Calculations Here
    
    //Output Located Here
    clas.prnScr();

    //Exit
    return 0;
}

