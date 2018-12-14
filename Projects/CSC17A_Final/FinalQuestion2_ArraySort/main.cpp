/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on December 13, 2018 12:16 PM
 * Purpose: 
 */

// i wasn't able to get this one to work 
// couldn't get it to run without a "build failed"


//System Libraries Here
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

//User Libraries Here
#include "Prob2Sort.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here

int main(int argc, char** argv) {
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort<char> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("data.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++)
    {
	    for(int j=0;j<16;j++)
	    {
		    cout<<zc[i*16+j];
	    }
    }
    delete []zc;
    cout<<endl;

    return 0;
}

