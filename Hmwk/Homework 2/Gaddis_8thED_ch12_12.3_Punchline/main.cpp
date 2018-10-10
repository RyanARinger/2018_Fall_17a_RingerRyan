/* 
 * File:   main.cpp
 * Author: Ryan Ringer 
 * Created on October 10, 2018 at 2:12pm
 * Purpose:  Hello World Template
 */

//System Libraries Here
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void readjok(ifstream&);
int count(ifstream&);
void readpun(ifstream&);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    string file1, file2;
    int size =0;
    ifstream inFile1, inFile2;
    
    //Input or initialize values Here
    cout << "Enter The name of your joke file: ";
    //Process/Calculations Here
    
    //Output Located Here

    //Exit
    return 0;
}
void readjok(ifstream &inFile1){
    char x;
    while(inFile1 >> noskipws >> x)
        cout << x;
}
int count(ifstream &inFile2){
    char x;
    int count = 0;
    while(inFile2 >> x){
        count++;
    }
    return count;
}
void readpun(ifstream &inFile2, int size){
    char a[size];
    int i=0;
    bool end = false;
    while(inFile2 >> noskipws >> a[i]){
        if((int)a[i] == 46){
            i = 0;
        }
    }
    for(int j=0; j<=i; j++){
        cout << a[j];
    }
}