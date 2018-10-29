
/* 
 * File:   CustStruct.h
 * Author: Ryan Ringer
 *
 * Created on October 25, 2018, 3:31 PM
 */

/*
a. Name
b. Address
c. Account number (Five digits only, i.e. test for this)
d. Balance at the beginning of the month 
e. Total of all checks written by this customer this month 
     Loop until customer is through entering checks.
f. Total of all deposits credited to this customer's account this 
     month.  Loop until customer is through entering deposits.
 */


#ifndef CUSTSTRUCT_H
#define CUSTSTRUCT_H
struct Customer{
    std :: string name;
    std :: string addy;
    char * acntnum;
    float strtbal;
    float curntbal = strtbal;
    int chcount = 0;
    int decount = 0;
};


#endif /* CUSTSTRUCT_H */

