/* 
 * File:   Circle.h
 * Author: Ryan Ringer
 * Purpose: Circle header Definition
 * Created on November 8, 2018, 4:19 PM
 */
#include <iostream>
using namespace std;
#include "Circle.h"

    float radius;
    float pi;


    Circle::Circle(){
        Circle::setRad(0);
        Circle::setPi(3.14159);
    }
    Circle::Circle(float r, float p){
        Circle::setRad(r);
        Circle::setPi(p);
    }
    void Circle::pCircle(){
        float r, d, c, a;
        r = Circle::getRad();
        d = Circle::getDiam();
        c = Circle::getCirc();
        a = Circle::getArea();
        
        cout << "Radius: " << r << endl << "Diameter: " << d << endl;
        cout << "Circumference: " << c << endl << "Area: " << a << endl;
    }