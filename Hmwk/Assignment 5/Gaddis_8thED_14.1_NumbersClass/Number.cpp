/* 
 * File:   Number.cpp
 * Author: Ryan Ringer
 * Purpose: 
 * Created on November 11, 2018, 7:03 PM
 */
#include <string>
#include <iostream>
using namespace std;

#include "Number.h"
    

Num::Num(int g){
    Num::setGiv(g);
    Num::fndFnl();
}

void Num::fndFnl(){
    int giv = Num::getGiv();
    int work;
    string end = "";

    
    // These statements will find the string set and add them together to get a final output
    if(giv == 0){
        end += "Zero";
    }
    else{
        if( giv < 0 ){
            end += "Negative ";
            giv = giv * -1;
        }
        if(giv >= 1000){
            work = giv / 1000;
            end += Num::nTeen[work];
            end += "Thousand ";
        }

        giv = giv % 1000;


        if(giv >= 100){
            work = giv / 100;
            end += Num::nTeen[work];
            end += "Hundred ";
        }

        giv = giv % 100;


        if(giv > 19){
            work = giv / 10;
            giv = giv % 10;
            end += Num::tens[work];
            end += Num::nTeen[giv];
        }
        else if(giv <= 19){
            end += Num::nTeen[giv];
        }
    }

    // Send the final string to the setter function
    Num::setFnl(end);
}

void Num::prnNum(){
    string out = Num::getFnl();
    
    cout << out;
    if(out == "Sixty Nine "){
        cout << " Nice" << endl;
    }
    else{
        cout << endl;
    }
}