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
int count(string);
void write(string, int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    string file;
    int c;
    //Input or initialize values Here
    cout << "Enter the name of the file you wish to read :";
    getline(cin, file, '\n');
    //Process/Calculations Here
    c = count(file);
    write(file, c);
    //Output Located Here

    //Exit
    return 0;
}
int count(string file){
    ifstream inFile;
    int c=0;
    char x;
    inFile.open(file, ios::in);
    while(inFile){
        inFile >> noskipws >> x;
        if((char)x == 10)
            c++;
    }
    inFile.close();
    return c;
}
void write(string file, int c){
    ifstream inFile;
    string line;
    string cont;
    int itt = (c/24) +1;
    int count = 0;
    int prntcnt = 0;
    inFile.open(file,ios::in);
    while(count < itt){
        for(int i=0; i<24; i++){   
            while(prntcnt <= c){
                getline(inFile, line, '\n');
                cout << line << endl;
                prntcnt++;
            }
        }
        getline(cin, cont, '\n');
        count++;
    }
    inFile.close();
}