/* 
 * File:   PersonClass.h
 * Author: Ryan Ringer
 * Purpose: Person Class Definition
 * Created on November 3, 2018, 11:32 AM
 */

#ifndef PERSONCLASS_H
#define PERSONCLASS_H
class Person{
    private:
        std::string name;
        std::string addy;
        int age;
        std::string phone;
    public:
        void setName(std::string n){ name = n; }
        
        void setAddy(std::string ad) { addy = ad; }
        
        void setAge(int a){ age = a; }
        
        void setPhne(std::string p) { phone = p; }
        
        std::string getName() const { return name; }
        
        std::string getAddy() const { return addy; }
        
        int getAge() const { return age; }
        
        std::string getPhne() const { return phone; }
        
        void prnInfo();
        
};


#endif /* PERSONCLASS_H */

