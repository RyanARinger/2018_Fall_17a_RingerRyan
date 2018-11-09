/* 
 * File:   inventory.h
 * Author: Ryan Ringer
 * Purpose: Inventory Class Definition
 * Created on November 7, 2018, 6:23 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
using namespace std;

class Invent{
    private:
        int id;
        int qty;
        float price, cost;
        
    public:
        Invent();
        Invent(int, int, float);
        void setId (int d) { id = d; }
        void setQty (int q) { qty = q; }
        void setPrice (float p) { price = p; }
        void setCost ();
        int getId () { return id; }
        int getQty () { return qty; }
        float getPrice () { return price; }
        float getCost () { return cost; }
        void prnItem ();
};


#endif /* INVENTORY_H */

