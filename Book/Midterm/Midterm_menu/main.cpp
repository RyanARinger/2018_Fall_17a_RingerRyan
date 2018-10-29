/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on September 8th, 2018 2:12pm
 * Purpose:  Mode Median Range
 */

// System Libraries Here
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// User Libraries Here
#include "CustStruct.h"
#include "EmpStruct.h"
#include "PrimeArrStruct.h"
#include "PrimeStruct.h"
// Global Constants Only, No Global Variables
// Like PI, e, Gravity, or conversions

// Function Prototypes Here
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
float check(float, float);
float deposit(float, float);
int paycalc(int, int);
void chprint(Emp);
char encrypt(char);
char decrypt(char);
// Program Execution Begins Here
int main(int argc, char** argv) {
    int choice;
    
    cout << "Welcome to the main menu. ";
    do {
        cout << "Enter the number 0 to exit.\n\n"
        "1) Checking Account\n"
        "2) Employee Pay \n"
        "3) Stats \n"
        "4) Encrypt And Decrypt\n"
        "5) Factorial Answer\n"
        "6) Number Conversions\n"
        "7) Prime Factorial \n"
        "\nEnter a number between 1-7 to select the program: ";
        cin >> choice;
        cin.ignore();
    
        switch(choice){
            case 0:    break;
            case 1:    cout<<endl<<endl;problem1();break; // CheckingAccountBalance
            case 2:    cout<<endl<<endl;problem2();break; // PayChecks
            case 3:    cout<<endl<<endl;problem3();break; // MeanMedianMode2.0 *Incomplete*
            case 4:    cout<<endl<<endl;problem4();break; // EncryptAndDectrypt
            case 5:    cout<<endl<<endl;problem5();break; // FactTester
            case 6:    cout<<endl<<endl;problem6();break; // BinOctHex *Incomplete*
            case 7:    cout<<endl<<endl;problem7();break; // PrimeFactor
            default:   cout << "Invalid Choice. ";
        }
        cout << "\n\n";
        } while(choice>0);

   return 0;
}
void problem1(){
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
}
void problem2(){
    // Declare all Variables Here
    int numemp;
    Emp * Team;
    
    // Input or initialize values Here
    cout << "How many employees? : ";
    cin >> numemp;
    cin.ignore();
    Team = new Emp [numemp];
    for(int i = 0; i < numemp; i++){
        cout << "Enter the name of employee #" << i+1 << " :";
        getline(cin,Team[i].name, '\n');
        cout << "Hours worked : ";
        cin >> Team[i].hrswrkd;
        cout << "Pay rate in dollars per hour :";
        cin >> Team[i].payrate;
        cin.ignore();
        Team[i].pay = paycalc(Team[i].hrswrkd, Team[i].payrate);

    }
    for(int i = 0; i < numemp; i++){
        chprint(Team[i]);
    }
    // Process/Calculations Here
    
    // Output Located Here
    

    // Exit
}
void problem3(){
    cout << "Not Completed" << endl;
}
void problem4(){
    //Declare all Variables Here
    const int SIZE = 4;
    char str;
    char a[SIZE];
    bool cont, de_en;
    do{
        cout << endl << "Encrypt(0) or Decrypt(1)? ";
        cin >> de_en;
        cout << endl << "Enter number: ";
        cin >> a;
        str = a[0];
        a[0] = a[2];
        a[2] = str;
        str = a[1];
        a[1] = a[3];
        a[3] = str;
        for(int i=0; i<SIZE; i++){
            if(!de_en){
                a[i] = encrypt(a[i]);
                cout << (int)a[i];
            }
            else{
                a[i] = decrypt(a[i]);
                cout << a[i];
            }
        }
        cout << endl << endl;
        cout << "Would you like to rerun? ((1)Yes or (0)No):";
        cin >> cont;
    }while(cont);
    //Exit
}
void problem5(){
        //Declare all Variables Here
    
    //Process/Calculations Here

    //Output Located Here
    cout << "Unsigned and Signed char: 5!" << endl;
    cout << "Signed Short: 7!" << endl;
    cout << "Unsigned Short: 8!" << endl;
    cout << "Unsigned and Signed int: 12!" << endl;
    cout << "float: 10!" << endl;
    cout << "Double: 10!" << endl;
    cout << "Unsigned long: 13!" << endl;
    cout << "Signed char: 12!" << endl;
    //Exit
}
void problem6(){
    cout << "Not Completed" << endl;
}
void problem7(){
    // Declare all Variables Here
    const int NPLTHUN = 25;
    int number;
    bool one;
    Primes prmcont;
    unsigned char prmnum[NPLTHUN] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    prmcont.primes = new Prime[NPLTHUN];

    // Input or initialize values Here
        for(int i = 0; i < NPLTHUN; i++){
        prmcont.primes[i].prime = prmnum[i];
        prmcont.primes[i].power = 0;
    }
    cout << "Enter a number between 2 and 10000: ";
    cin >> number;
    
    // Process/Calculations Here

        for(int i = 0; i<NPLTHUN; i++){
            do{
                one = true;
                if(number % prmcont.primes[i].prime == 0){
                    number /= prmcont.primes[i].prime;
                   prmcont.primes[i].power++;
                   one = false;
                }
            }while(!one);
        }

    // Output Located Here
    cout << number << "-> ";
    for(int i=0; i<NPLTHUN; i++){
        if(prmcont.primes[i].power != 0)
            cout << (int)prmcont.primes[i].prime << "^" << (int)prmcont.primes[i].power << " * ";
    }

    // Exit
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
int paycalc(int hours, int rate){
    int pay = 0;
    int wrknum;
    if(hours > 40){
        pay = 40 * rate;
        hours -= 40;
        if(hours > 10){
            wrknum = 10 * (rate * 2);
            pay += wrknum;
            hours-=10;
            wrknum = hours * (rate * 3);
            pay += wrknum;
        }
        else{
            wrknum = hours * (rate * 2);
            pay += wrknum;
        }
    }
    else{
        pay = hours * rate;
    }
    return pay;
}
void chprint(Emp minion){
    int width = 35;
    cout << "Company : Mediocre Coding LLC" << endl;
    cout << "Address : 1234 Dropout st." << endl;
    cout << "Name: " << minion.name << setw(width) << "Amount: $" << minion.pay << endl;
    cout << "Signature X______________________________" << endl << endl << endl;
}
char encrypt(char a){
    char b = a;
    b +=5;
    b = b%8;
    return b;
}
char decrypt(char a){
    char b = a;
    //cout << b;
    if(b < '5'){
        b += 8;
    }
    b -= 5;
    return b;
}