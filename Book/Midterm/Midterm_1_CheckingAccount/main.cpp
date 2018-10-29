/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on October 26th, 2018 3:28pm
 * Purpose:  Mode Median Range
 */
/*1)  Develop an application using structures for a customer
that will determine if he/she has exceeded his/her checking 
account balance. For each customer, the following 
facts are available:

a. Name
b. Address
c. Account number (Five digits only, i.e. test for this)
d. Balance at the beginning of the month 
e. Total of all checks written by this customer this month 
     Loop until customer is through entering checks.
f. Total of all deposits credited to this customer's account this 
     month.  Loop until customer is through entering deposits.

Dynamically create the structure.
The program should input each of these facts from input dialogs,
store in a structure, calculate the new balance, 
display the new balance and debit the account $20 if overdrawn. 
Also, if overdrawn, tell the customer the additional $20 fee 
has been accessed and what the balance would be with this fee included.
Make sure to output the contents of the structure.
*/

//System Libraries Here
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries Here
#include "CustStruct.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
float check(float, float);
float deposit(float, float);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Constants
    const int SIZE = 5;
    
    //Declare all Variables Here
    Customer Cust;
    Cust.acntnum = new char[SIZE];
    int count = 0;
    bool chorde, action;
    float amt;
    int width = 15;
    
    //Input or initialize values Here
    cout << "Enter the name of the Customer: ";
    getline(cin,Cust.name,'\n');
    cout << "Enter the five digit account number (will cut off after five digits) : ";
    cin >> Cust.acntnum;
    cout << "What is the balance at the beginning of the month? : $";
    cin >> Cust.strtbal;
    Cust.curntbal = Cust.strtbal;
    
    //Process/Calculations Here
    cout << "would you like to take action on this account? (yes (1) or no(0):";
    cin >> action;
    do{
        cout << "Withdrawal(1) or deposit(0)? ";
        cin >> chorde;
        cout << "How much? : $";
        cin >> amt;
        if(chorde){
            Cust.curntbal = check(amt, Cust.curntbal);
            Cust.chcount += 1;
        }
        if(!chorde){
            Cust.curntbal = deposit(amt, Cust.curntbal);
            Cust.decount += 1;
        }
        cout << "would you like to take another action on this account? (yes (1) or no(0):";
        cin >> action;
    }while(action);
    cout << fixed << setprecision(2);
    cout << "Account Holder :    " << setw(width)<< Cust.name << endl;
    cout << "Account Number :    " << setw(width)<< Cust.acntnum << endl;
    cout << "Starting balance : $" << setw(width)<< Cust.strtbal << endl;
    cout << "Current balance :  $" << setw(width)<< Cust.curntbal << endl;
    cout << "Number of Checks :  " << setw(width)<< Cust.chcount << endl;
    cout << "Number of deposits :" << setw(width)<< Cust.decount << endl;
    //Exit
    return 0;
}
float check(float dollars, float bal){
    float newbal = bal - dollars;
    if(newbal < 0){
        cout << "You have overdrawn and been charged a $20 fee" << endl;
        newbal -= 20;
    }
    return newbal;
}
float deposit(float dollars, float bal){
    float newbal = bal + dollars;
    return newbal;
}