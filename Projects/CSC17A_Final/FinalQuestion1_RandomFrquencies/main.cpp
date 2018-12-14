/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on December 13, 2018 11:36 AM
 * Purpose: 
 */


//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "prob1random.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    char n=5;
    char rndseq[]={18,33,56,79,125};
    int ntimes=100000;
    P1Rand a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
	    a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
	    cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;

//    delete[] x;
//    delete[] y;
    
    return 0;
}

