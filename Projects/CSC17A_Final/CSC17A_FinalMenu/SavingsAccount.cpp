/* 
 * File:   SavingsAccount.cpp
 * Author: Ryan Ringer
 * Created on December 13, 2018 7:57 PM
 * Purpose: 
 */


#include <iostream>
using namespace std;

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(float b) {
    if (balance > 0) { // Initializes the balance if greater than 0
        balance = b;
    } 
    else this->balance = 0;
   
    this->freqWithDraw = 0;
    this->freqDeposit = 0;
}

void SavingsAccount::transaction(float amount) {
    if (amount > 0) {
        this->freqDeposit++; 
        this->balance += amount;
    } 
    else { 
        if ((this->balance + amount) < 0) { 
            std::cout << "WithDraw not Allowed" << std::endl;
            return;
        }
        this->freqWithDraw++; 
        this->balance += amount;
    }
}

float SavingsAccount::total(float savings, int time) {
    float power = 1;
    for (int i = 0; i < time; i++) { 
        power *= 1 + savings;
    }
    return this->balance * power; 
}

float SavingsAccount::totalRecursive(float savings, int time){
    if (time == 0) {
        return this->balance; 
    }
    
    return (savings + 1) * totalRecursive(savings, time - 1); 
}

void SavingsAccount::toString() { 
    cout << "Balance = " << this->balance << std::endl;
    cout << "WithDraw = " << this->freqWithDraw << std::endl;
    cout << "Deposit = " << this->freqDeposit << std::endl;
}