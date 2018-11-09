/* 
 * File:   Scores.h
 * Author: Ryan Ringer
 * Purpose: Test Scores Class Initialization
 * Created on November 7, 2018, 7:05 PM
 */

#ifndef SCORES_H
#define SCORES_H

class Scores{
    private:
        float score1;
        float score2;
        float score3;
        float avgscr;
    public:
        Scores(float, float, float);
        void setScor1(float one) { score1 = one; }
        void setScor2(float two) { score2 = two; }
        void setScor3(float three) { score3 = three; }
        void setavg(float four) { avgscr = four; }
        float getScr1() const { return score1; }
        float getScr2() const { return score2; }
        float getScr3() const { return score3; }
        float getAvg() const { return avgscr; }
        void scrAvg();
        void prnScr ();
        
};


#endif /* SCORES_H */

