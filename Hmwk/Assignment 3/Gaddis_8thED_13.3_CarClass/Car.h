/* 
 * File:   Car.h
 * Author: Ryan Ringer
 * Purpose: Car class initialization
 * Created on November 5, 2018, 8:22 PM
 */

#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car{ 
    private:
        int model;
        string make;
        int speed;
    public:
        Car(int, string);
        void accelerate();
        void brake();
        int getMod() const { return model; }
        string getMake() const { return make; }
        int getSpd() const { return speed; }
        void prnSpd();        
};


#endif /* CAR_H */

