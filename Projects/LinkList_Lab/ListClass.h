/* 
 * File:   ListClass.h
 * Author: Ryan Ringer
 * Purpose: List class creation
 * Created on November 21, 2018, 2:43 PM
 */

#ifndef LISTCLASS_H
#define LISTCLASS_H
#include "NodeStruct.h"

class List{
    private:
        Node * list;
    public:
        List(){ list = new Node; }
        ~List();
        
        
};

#endif /* LISTCLASS_H */

