/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on October 5th 2018 11:33am
 * Purpose:  Risk
 */

//System Libraries Here
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

//User Libraries Here
#include "CardStruct.h"
#include "NationStruct.h"
#include "GameboardStruct.h"

//Global Constants Only, No Global Variables


//Like PI, e, Gravity, or conversions


//Function Prototypes Here
int dieroll();                  // Rolls a die
int contcou();                  // Asks user for number of nations
Card *deckset (int);            // Uses the number of nations to create an array of Card structures
Gamebrd gameset(int);           // Sets up the game board
void frstplr();
void destroy(Card *);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int nContry = contcou();
    Card* Deck = deckset(nContry);
    //Input or initialize values Here
    
    //Process/Calculations Here
    
    //Output Located Here
    for(int i = 0; i < nContry; i++){
        if(Deck[i].wild)cout << "Wild Card" << endl;
        else{
            cout <<"Nation #" << Deck[i].nation << "  # of Armies: " << Deck[i].armies << endl;
        }
    }
    // Destroy
    destroy(Deck);
    //Exit
    return 0;
}
int dieroll(){
    /*
     * This function uses a random number modded with six in 
     * order to get a random dice roll on a six sided die
     */
    int roll = rand()%6+1;
    return roll;
}
int contcou(){
    /*
     * This function asks the player for a number of nations 
     * that will be used in his/her game
     */
    int nContry;
    do{
        cout << "Enter the number of nations for your game of Risk(Max 42): ";
        cin >> nContry;
        if(nContry<0||nContry>42)cout << "ERROR: game will not accept a negative number or a number greater than 42!" << endl << "Try Again" << endl;
    }while (nContry<0||nContry>42);
    return nContry;
}
Card *deckset (int n){
    int j = 0;
    const int HAND = 44;
    Card * Deck = new Card[HAND];
    int give;
    bool twoWld = false;
    int wldcont = 0;
    for (int i=0; i<n; i++){
        give = rand()%21;
        if(give == 0){
            Deck[i].wild = true;
        }
        if(Deck[i].wild){
            if (!twoWld){
                Deck[i].nation = 0;
                Deck[i].armies = 0;
                Deck[i].wild = true;
                wldcont++;
                if(wldcont == 2)twoWld=true;
               
            }
            else{
                Deck[i].nation = i+1;
                Deck[i].armies = rand()%6;
                Deck[i].wild = false;
            }
        }
        else{
            Deck[i].nation = i+1;
            Deck[i].armies = rand()%7+1;
        }
    }
    return Deck;
}
Gamebrd gameset(int){
    
}
void frstplr(){
    int roll;
    roll = rand()%6+1;
}
void destroy(Card * a){
    delete []a;
}