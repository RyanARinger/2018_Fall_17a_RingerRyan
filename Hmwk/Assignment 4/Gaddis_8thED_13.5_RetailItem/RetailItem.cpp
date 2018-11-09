/* 
 * File:   RetailItem.h
 * Author: Ryan Ringer
 * Purpose: RetailItem Definition
 * Created on November 7, 2018, 11:31 AM
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "RetailItem.h"


    string des;
    int qty;
    float price;

    RItem::RItem(string d, int q, float p){
        RItem::setDes(d);
        RItem::setQty(q);
        RItem::setPrice(p);
    }
    void RItem::prnItem (){
        string d = RItem::getDes();
        int q = RItem::getQty();
        float p = RItem::getPrice();
        
        cout << fixed << setprecision(2);
        cout << "Description : " << d << " Quantity: " << q << " Price: " << p << endl;
        
    }