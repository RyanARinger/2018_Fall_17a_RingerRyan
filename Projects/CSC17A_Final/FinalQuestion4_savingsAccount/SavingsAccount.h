/* 
 * File:   SavingsAccount.h
 * Author: Ryan Ringer
 * Created on December 13, 2018 7:57 PM
 * Purpose: 
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount{
private:
    float withdraw(float);               //Utility Procedure
    float deposit(float);                //Utility Procedure
    float balance;                       //Property
    int   freqWithDraw;                  //Property
    int   freqDeposit;                   //Property
    
public:
    SavingsAccount(float);               //Constructor
    void  transaction(float);            //Procedure
    float total(float=0,int=0);	         //Savings Procedure
    float totalRecursive(float=0,int=0);
    void  toString();                    //Output Properties
};

#endif /* SAVINGSACCOUNT_H */

