/* 
 * File:   DateClass.h
 * Author: Ryan Ringer
 * Purpose: Class Definition
 * Created on November 2, 2018, 10:10 PM
 */

#ifndef DATECLASS_H
#define DATECLASS_H
class Date{
    private:
        int month;
        int day;
        int year;
        
    public:
        void setMnth(int m){ month = m; }
        
        void setDay(int d){ day = d; }
        
        void setYear(int y){ year = y; }
        
        int getMnth() const{ return month; }
        
        int getDay() const{ return day; }
        
        int getYear() const{ return year; }
        
        void prnDate();
        
};


#endif /* DATECLASS_H */

