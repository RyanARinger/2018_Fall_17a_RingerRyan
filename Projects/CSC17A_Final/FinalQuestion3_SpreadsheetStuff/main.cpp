/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on December 13, 2018 3:11 PM
 * Purpose: 
 */


// Couldn't get this one to work either


//System Libraries Here
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

//User Libraries Here
#include "Prob3Table.h"
#include "Prob3TableInherited.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here

int main(int argc, char** argv) {
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    string fileName = "data.txt";
    ifstream inFile;
    inFile.open(fileName, ios::in);


    int ** table = new int*[cols];
    for(int i=0; i<cols; i++){
	table[i] = new int[rows];
    }

    for(int i=0; i<rows; i++){
	for(int j=0; j<cols; j++){
	    inFile >> table[i][j];
	}
    }
    Prob3TableInherited<int> tab(table,rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
	    for(int j=0;j<cols;j++)
	    {
		    cout<<naugT[i*cols+j]<<" ";
	    }
	    cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
	    for(int j=0;j<=cols;j++)
	    {
		    cout<<augT[i*(cols+1)+j]<<" ";
	    }
	    cout<<endl;
    }

    return 0;
}

