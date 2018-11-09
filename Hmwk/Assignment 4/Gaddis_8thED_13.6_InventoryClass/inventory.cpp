/* 
 * File:   RetailItem.h
 * Author: Ryan Ringer
 * Purpose: RetailItem Initialization
 * Created on November 7, 2018, 11:31 AM
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "inventory.h"


    Invent::Invent(){
        Invent::setId(0);
        Invent::setQty(0);
        Invent::setPrice(0);
        Invent::setCost();
    }
    Invent::Invent(int i, int q, float p){
        Invent::setId(i);
        Invent::setQty(q);
        Invent::setPrice(p);
        Invent::setCost();
    }
    void Invent::setCost(){
        float p = Invent::getPrice();
        int q = Invent::getQty();
        float c = p*q;
        cost = c;
    }
    void Invent::prnItem (){
        int d = Invent::getId();
        int q = Invent::getQty();
        float p = Invent::getPrice();
        float c = Invent::getCost();
        cout << fixed << setprecision(2);
        cout << "Item Number: " << d << " Quantity: " << q << " Price: $" << p << " Total Inventory Worth: $" << c << endl;
        
    }