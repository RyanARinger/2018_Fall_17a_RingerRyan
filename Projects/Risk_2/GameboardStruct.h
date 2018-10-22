/* 
 * File:   CardStruct.h
 * Author: Ryan Ringer
 *
 * Created on October 14, 2018, 1:17 PM
 */
#include "PlayerStruct.h"
#include "CardStruct.h"
#include "NationStruct.h"

#ifndef GAMEBOARDSTRUCT_H
#define GAMEBOARDSTRUCT_H

struct Gamebrd{
    Nation * World;
    Card * Deck;
    Player * Gens;
};


#endif /* GAMEBOARDSTRUCT_H */

