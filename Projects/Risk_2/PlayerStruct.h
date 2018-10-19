/* 
 * File:   NationStruct.h
 * Author: Ryan Ringer
 *
 * Created on October 12, 2018, 8:33 PM
 */
#include "CardStruct.h"
#ifndef PLAYERSTRUCT_H
#define PLAYERSTRUCT_H

struct Player{
    std :: string name;
    Card * Hand;
};

#endif /* PLAYERSTRUCT_H */

