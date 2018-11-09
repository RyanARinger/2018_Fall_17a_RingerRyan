/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on November 6th, 2018, 3:11 PM
 * Purpose:  RetailItem class problem
 */

//System Libraries Here
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries Here
#include "inventory.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Constant Variable
    const int SIZE = 3;
    
    //Declare all Variables Here
    int id[SIZE];
    int qtys[SIZE];
    float prices[SIZE];
    for(int i = 0; i<SIZE; i++){
        cout << "Enter item # " << i+1 << "'s Item Number: ";
        cin >> id[i];
               
        cout << "Enter item # " << i+1 << "'s Quantity: ";
        cin >>  qtys[i];
        
        cout << "Enter item # " << i+1 << "'s Price: $";
        cin >>  prices[i];
        
    }
    Invent item1(id[0], qtys[0], prices[0]);
    Invent item2(id[1], qtys[1], prices[1]);
    Invent item3(id[2], qtys[2], prices[2]);
    //Input or initialize values Here
    
    //Process/Calculations Here
    
    
    //Output Located Here
    item1.prnItem();
    item2.prnItem();
    item3.prnItem();
    //Exit
    
    return 0;
}