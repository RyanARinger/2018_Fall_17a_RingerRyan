/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 *
 * Created on December 11, 2018, 8:04 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

#include "SavingsAccount.h"

//Execution Begins Here

int main(int argc, char** argv) {

    srand(static_cast<unsigned int>(time(0)));
    
    SavingsAccount acct(-300);

    for(int i=1;i<=10;i++) {
        acct.transaction((float)(rand()%500)*(rand()%3-1));
    }
    
    acct.toString();
    
    cout<<"Balance after 7 years given 10% interest = "
            << acct.total((float)(0.10),7) << endl;
    
    cout<<"Balance after 7 years given 10% interest = "
            << acct.totalRecursive((float)(0.10),7)
            <<" Recursive Calculation " << endl;
    
    return 0;
}
