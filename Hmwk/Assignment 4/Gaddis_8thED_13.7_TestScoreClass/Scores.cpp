/* 
 * File:   Scores.cpp
 * Author: Ryan Ringer
 * Purpose: Test Scores Class Definition
 * Created on November 7, 2018, 7:05 PM
 */
#include <iostream>
using namespace std;
#include "Scores.h"

    Scores::Scores(float a, float b, float c){
        Scores::setScor1(a);
        Scores::setScor2(b);
        Scores::setScor3(c);
        Scores::scrAvg();
    }

    void Scores::scrAvg(){
        const int SIZE = 3;
        float avg;
        float scrs[SIZE];
        scrs[0] = Scores::getScr1();
        scrs[1] = Scores::getScr2();
        scrs[2] = Scores::getScr3();
        for(int i = 0; i<SIZE; i++){
            avg += scrs[i];
        }
        avg /= SIZE;
        Scores::setavg(avg);
    }
    
    void Scores::prnScr(){
        const int SIZE = 3;
        float s[SIZE];
        float avg = Scores::getAvg();
        s[0] = Scores::getScr1();
        s[1] = Scores::getScr2();
        s[2] = Scores::getScr3();
        
        for(int i=0; i<SIZE; i++){
            cout << "Score #" << i+1 << ": " << s[i] << endl;
        }
        cout << "Average: " << avg << endl;
    }


