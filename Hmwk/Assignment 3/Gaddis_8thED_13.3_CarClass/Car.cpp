/* 
 * File:   Car.h
 * Author: Ryan Ringer
 * Purpose: Car class initialization
 * Created on November 5, 2018, 8:31 PM
 */

#include <iostream>
#include <string>
using namespace std;

#include "Car.h"

    Car::Car(int mo, string ma){
        model = mo;
        make = ma;
        speed = 0;
    }
    void Car::accelerate(){
        cout << "Accelerate, Current speed: ";
        speed += 5;
    }
    void Car::brake(){
        cout << "Brake, Current speed: ";
        speed -= 5;
    }
    void Car::prnSpd(){
        int sp = Car::getSpd();
        cout << sp << endl;
    }