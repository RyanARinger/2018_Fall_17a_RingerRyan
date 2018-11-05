/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on September 8th, 2018 2:12pm
 * Purpose:  Mode Median Range
 */

//System Libraries Here
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries Here
#include "SalesStruct.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
float *salegrb(string, int);
void write(Divsale *, string, int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int DIVISIN = 4;
    Divsale *corp = new Divsale[DIVISIN];
    string file;
    //Input or initialize values Here
    cout << "Enter the name of the file you wish to write to :";
    getline(cin, file, '\n');
    for(int i=0; i<DIVISIN; i++){
        corp[i].size=4;
    }
    
    for(int i=0; i<DIVISIN; i++){
        cout << "Enter the name of division #" << i+1 << " : ";
        cin >> corp[i].divis;
    }
    for (int i=0; i<DIVISIN; i++){
        corp[i].quarter = salegrb(corp[i].divis,corp[i].size);
    }
    //Process/Calculations Here
    write (corp, file, DIVISIN);
    //Output Located Here
    

    //Exit
    return 0;
}
float *salegrb(string divis, int size){
    float * sales= new float[size];
    
    for (int i=0; i<size; i++){
        cout << "Enter the sales for the " << divis <<" division's " << i+1 << " quarter : ";
        cin >> sales[i];
    }
    return sales;
}
void write (Divsale *corp, string file, int divisin){
    ofstream outFile;
    outFile.open(file, ios::out);
    
    for(int i=0; i<divisin; i++){
        outFile <<" [ " << corp[i].divis << " Division : ";
        for(int j=0; j<corp[i].size; j++){
            outFile << endl <<" Quarter #" << j+1 <<" sales : $" << corp[i].quarter[j];
        }
        outFile << "] ";
    }
}