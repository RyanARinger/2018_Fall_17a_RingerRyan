/* 
 * File:   Circle.h
 * Author: Ryan Ringer
 * Purpose: Circle header initialization
 * Created on November 8, 2018, 4:19 PM
 */

#ifndef CIRCLE_H
#define CIRCLE_H
class Circle{
    private:
        float radius;
        float pi;
    public:
        Circle();
        Circle(float, float);
        void setRad(float r) { radius = r; }
        void setPi(float p) { pi = p; }
        float getRad() const { return radius; }
        float getPi() const { return pi; }
        float getArea() { return pi * radius * radius; }
        float getDiam() { return radius * 2; }
        float getCirc() { return radius * 2 * pi; }
        void pCircle();
};


#endif /* CIRCLE_H */

