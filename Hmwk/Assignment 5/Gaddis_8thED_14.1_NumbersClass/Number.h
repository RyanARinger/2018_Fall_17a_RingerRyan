/* 
 * File:   Number.h
 * Author: Ryan Ringer
 * Purpose: Num Class Initialization
 * Created on November 11, 2018, 4:41 PM
 */

#ifndef NUMBER_H
#define NUMBER_H

#include <string>
using namespace std;

class Num{
    
    private:
        int given;        
        string fnl;
        string nTeen [21] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ",
                             "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
        string tens [10] = {"", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};

    public:
        Num(int g);
        void setGiv(int g) { given = g; }
        void setFnl(string f) { fnl = f; }
        void fndFnl();
        int getGiv() const {return given;}
        string getFnl() const {return fnl;}
        void prnNum ();
        
};


#endif /* NUMBER_H */

