/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on September 26, 2018, 10:30 AM
 * Purpose:  File Head
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
void write(string);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    string file;
    //Input or initialize values Here
    cout << "Enter the name of the file you wish to read :";
    getline(cin, file, '\n');
    //Process/Calculations Here
    write(file);
    //Output Located Here

    //Exit
    return 0;
}
void write(string file){
    ifstream inFile;
    string line;
    inFile.open(file,ios::in);
    
    for(int i=0; i<10; i++){
        getline(inFile, line, '\n');
        cout << line << endl;
    }
}