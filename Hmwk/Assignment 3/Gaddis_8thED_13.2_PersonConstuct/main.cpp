/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on November 4th, 2018, 2:15 AM
 * Purpose:  File Head
 */

//System Libraries Here
#include <iostream>
#include <string>

using namespace std;

//User Libraries Here
#include "Employee.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Constant Variable
    const int NP = 3;
    //Declare all Variables Here
    string n[NP];
    int id[NP];
    string dept[NP];
    string pos[NP];
    for(int i = 0; i<NP; i++){
        cout << "Enter employee " << i+1 <<  "'s name ( if no info press enter ) : ";
        getline(cin, n[i], '\n');
        
        cout << "Enter employee " << i+1 <<  "'s ID number ( if no info press enter ) : ";
        cin >> id[i];
        cin.ignore();
        
        cout << "Enter employee " << i+1 <<  "'s department ( if no info press enter ) : ";
        getline(cin, dept[i], '\n');
        
        cout << "Enter employee " << i+1 <<  "'s Position ( if no info press enter ) : ";
        getline(cin, pos[i], '\n');        
        
    }
    
    Empl p1(n[0], id[0], dept[0], pos[0]);
    Empl p2(n[1], id[1], dept[1], pos[1]);
    Empl p3(n[2], id[2], dept[2], pos[2]);
    //Input or initialize values Here

    //Process/Calculations Here
    
    //Output Located Here
    p1.prnEmp();
    p2.prnEmp();
    p3.prnEmp();
    //Exit
    
    return 0;
}