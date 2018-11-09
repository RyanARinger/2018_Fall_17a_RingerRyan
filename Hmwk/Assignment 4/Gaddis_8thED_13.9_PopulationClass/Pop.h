/* 
 * File:   Pop.h
 * Author: Ryan Ringer
 * Purpose: 
 * Created on November 8, 2018, 5:04 PM
 */

#ifndef POP_H
#define POP_H
class Pop{
    private:
        float popNum;
        float numDed;
        float numBrth;
        float dRate;
        float bRate;
    public:
        Pop(float, float, float);
        void setPop(float p) { popNum = p; }
        void setDed(float d) { numDed = d; }
        void setBrn(float b) { numBrth = b; }
        void setDR() { dRate = numDed / popNum; }
        void setBR() { bRate = numBrth /popNum; }
        float getPop() const { return popNum; }
        float getDed() const { return numDed; }
        float getBrn() const { return numBrth; }
        float getDR() const { return dRate; }
        float getBR() const { return bRate; }
        void prnPop();
};


#endif /* POP_H */

