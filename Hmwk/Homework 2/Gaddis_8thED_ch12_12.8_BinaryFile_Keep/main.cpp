/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on September 25th, 2018 7:39pm
 * Purpose:  Binary File Array
 */

//System Libraries Here
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void filearr(string, int*, int);    // File to Array
void arrfile(string, int*, int);    // Array to File
void destroy(int*);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size = 10;
    int* a = new int[size];
    for(int i=0; i<size; i++){
        a[i] = i;    
    }
    string file;
    //Input or initialize values Here
    cout << "Enter the name of the file to write to: ";
    cin >> file;
    //Process/Calculations Here
    filearr(file, a, size);
    arrfile(file, a, size);
    //Output Located Here
    

    //Exit
    return 0;
}
void filearr(string file, int* a, int size){ 
    ofstream outFile;
    outFile.open(file, ios::out | ios::binary);
    outFile.write(reinterpret_cast<char*>(a), sizeof(a));
    outFile.close();
}
void arrfile(string file, int* a, int size){
    ifstream inFile;
    inFile.open(file, ios::in | ios::binary);
    inFile.read(reinterpret_cast<char *>(a), sizeof(a));
    inFile.close();
    
    for (int i=0; i<size; i++){
        cout << a[i] << " ";
    }
}
void destroy(int* a){
    delete []a;
}