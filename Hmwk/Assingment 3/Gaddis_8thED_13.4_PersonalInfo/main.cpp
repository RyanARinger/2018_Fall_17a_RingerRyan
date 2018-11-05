/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on November 3rd, 2018 11:32 AM
 * Purpose:  Personal Info Class Implementation
 */

// System Libraries Here
#include <iostream>
#include <string>
using namespace std;

// User Libraries Here
#include "PersonClass.h"
// Global Constants Only, No Global Variables
// Like PI, e, Gravity, or conversions

// Function Prototypes Here

// Program Execution Begins Here
int main(int argc, char** argv) {
    // Constant Variables
    const int NUMP = 3;
    // Declare all Variables Here
    Person People[NUMP];
    string name, address, phone;
    int age;
    
    // Input or initialize values Here
    for(int i=0; i<NUMP; i++){
        
        cout << "Enter Person " << i+1 << "'s name :";
        getline(cin,name,'\n');
        People[i].setName(name);
        cout << "Enter Person " << i+1 << "'s Address :";

        getline(cin,address,'\n');
        People[i].setAddy(address);
        cout << "Enter Person " << i+1 << "'s Age :";
        cin >> age;
        cin.ignore();
        People[i].setAge(age);
        
        cout << "Enter Person " << i+1 << "'s Phone Number :";
        getline(cin,phone,'\n');
        People[i].setPhne(phone);
        
        cout << endl;
    }
    // Process/Calculations Here
    
    // Output Located Here
    for(int i = 0; i < NUMP; i++){
        People[i].prnInfo();
        cout << endl << endl;
    }

    // Exit
    return 0;
}
