/* 
 * File:   Pop.cpp
 * Author: Ryan Ringer
 * Purpose: 
 * Created on November 8, 2018, 5:12 PM
 */

#include <iostream>
using namespace std;
#include "Pop.h"

Pop::Pop(float p, float b, float d){
    Pop::setPop(p);
    Pop::setDed(d);
    Pop::setBrn(b);
    Pop::setDR();
    Pop::setBR();
    Pop::prnPop();
}
void Pop::prnPop(){
    cout << "Population: " << Pop::popNum << " Number of Births: " << Pop::numBrth << " Number of Deaths: " << Pop::numDed << endl;
    cout << "Birth Rate: " << Pop::bRate << " Death Rate: " << Pop::dRate  << endl;
}