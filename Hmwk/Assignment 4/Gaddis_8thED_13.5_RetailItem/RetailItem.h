/* 
 * File:   RetailItem.h
 * Author: Ryan Ringer
 * Purpose: RetailItem Initialization
 * Created on November 7, 2018, 11:31 AM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H

#include <string>
using namespace std;

class RItem{
    private:
        string des;
        int qty;
        float price;
    public:
        RItem(string, int, float);
        void setDes (string d) { des = d; }
        void setQty (int q) { qty = q; }
        void setPrice (float p) { price = p; }
        string getDes () { return des; }
        int getQty () { return qty; }
        float getPrice () { return price; }
        void prnItem ();
};


#endif /* RETAILITEM_H */

