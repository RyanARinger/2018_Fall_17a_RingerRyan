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
#include <iomanip>
using namespace std;

//User Libraries Here
#include "CardStruct.h"
#include "NationStruct.h"
#include "GameboardStruct.h"

//Global Constants Only, No Global Variables


//Like PI, e, Gravity, or conversions


//Function Prototypes Here
int dieroll(); // written
int contcou(); // written
bool hqscan(); // written
bool frstplr(); // written
Card *deckset (int); // written
void shuffle(Card *, int); // written
void armset(Card*, Card*, Nation*, int, bool); // written
Gamebrd gameset(int); // written
char * hqset (Nation*, int); // written
void binwrte(char *, string); // written
bool victst(string, int); // written
void prnnat(Nation *, int); // written
void armplc(Nation *, Player , Player ,int); // written
void turn(int, Gamebrd);
int battle(Nation *, Player , Player , int); // written
void trdin (Card*, Player);
bool adjtest (int, int);
void destroy( Card *, Nation *, Player *, char *, const int);

//Program Execution Begins Here
int main(int argc, char** argv) {///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int DECK = 44;
    const int PLRS = 2;
    int nContry;
    int trdins = 0;
    bool plr1, hqyn;
    bool victory = false;
    char * hqs;
    string file = "data.bin";
    //Card* Deck = deckset(nContry);
    Gamebrd Board;
    
    
    //Input or initialize values Here
    hqyn = hqscan();
    nContry = contcou();
    Board = gameset(nContry);
    plr1 = frstplr();
    
    armplc(Board.World, Board.Gens[0], Board.Gens[1], nContry);
    //Process/Calculations Here
    battle(Board.World, Board.Gens[0], Board.Gens[1], nContry);
    //Output Located Here
    
    // Destroy
    //destroy(Board.Deck, Board.World, Board.Gens, hqs , PLRS);
    
    //Exit
    return 0;
}///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
     * (features input validation)
     */
    int nContry;
    do{
        cout << "Enter an even number of nations for your game of Risk(Min 4/ Max 42): ";
        cin >> nContry;
        if(nContry<4 || nContry>42 || nContry%2 == 1)
            cout << "ERROR: game will not accept an even number less than 4 or a number greater than 42!" << endl << "Try Again" << endl;
    }while (nContry<4||nContry>42||nContry%2 == 1);
    return nContry;
}
bool hqscan(){
    /* 
     * This function will ask a user whether they want to play
     * a shorter game of Risk
     * (features input validation)
     */
    int hqyn;
    do{
    cout << "Will you be playing a shorter Headquarters game of Risk today? (yes(1) or No(0): ";
    cin >> hqyn;
    if(hqyn < 0 || hqyn > 1)
        cout << "ERROR: Input must be either 0 or 1" << endl << "Try Again" << endl;
    }while(hqyn > 1|| hqyn <0);
    return hqyn;
}
bool frstplr(){
    int roll1, roll2;
    bool equal = false;
    do{
        roll1 = dieroll();
        roll2 = dieroll();
        if(roll1>roll2)return true;
        else if(roll2>roll1)return false;
        else equal = true;
    
    }while(equal);
}
Card *deckset (int n){
    int j=0;
    const int HAND = 44;
    Card * Deck = new Card[HAND];
    for (int i=0; i<n; i++){
        Deck[i].nation = i;
        Deck[i].armies = rand()%7+1;
        j++;
    }
    for(int i = j; i < n+2; i++){
        Deck[i].wild = true;
    }
    return Deck;
}
void shuffle(Card * A, int n){
    int randidx;
    Card Str;
    n += 2;
    for(int i=0; i<n; i++){
        randidx = rand()%n;
        Str = A[randidx];
        A[randidx] = A[i];
        A[i] = Str;
        
    }
}
void armset(Card* B, Card* R, Nation* C, int d){
    /*
     * This function places the initial armies
     */
    for(int i =0; i<=d; i++){ /*blue*/
        if(B[i].wild)
            C[B[i].nation];
        else
            C[B[i].nation].bluarmy ++;
    }
    for(int i =0; i<=d; i++){ /*red*/
        if(R[i].wild)
            C[R[i].nation];
        else
            C[R[i].nation].redarmy ++;
    }
}
Gamebrd gameset(int nCont){
    /* 
     * This Function creates a Game Board made of the players,
     * cards, and the countries themselves
     */
    const unsigned int SIZE = 44;
    const int NUMPLRS = 2;
    Gamebrd Board;
    string playername;
    int deal, hqset;
    int contmax = nCont + 2;
    Board.World = new Nation[nCont];
    Board.Gens = new Player[NUMPLRS];
    Board.Gens[0].Hand = new Card[SIZE/2];
    Board.Gens[1].Hand = new Card[SIZE/2];
    /* 
     * Here is the initialization of the array of Nation Structures
     * The array is determined by the number of nations chosen by the player
     */
    
    for(int i=0; i<nCont; i++){
        Board.World[i].name = i;
    }
    /* 
     * Here is the initialization of the array of Player Structures
     */
    
    cout << "What is your name? General ";
    cin >> Board.Gens[0].name;
    Board.Gens[1].name = "Si-Piyu";
    /* 
     * Here is the initialization of the array of Card Structures
     * This utilizes the deckset function to make a unique deck
     * then it calls the shuffle function
     */
    Board.Deck = new Card[SIZE];
    Board.Deck = deckset(nCont);
    shuffle(Board.Deck, nCont);
    deal = contmax/2;
//    for(int i =0; i<(nCont+2); i++){
//        if(!Board.Deck[i].wild)
//            cout << "Nation #" << Board.Deck[i].nation << " / # of Armies: " << Board.Deck[i].armies << endl;
//        else
//            cout << "WildCard" << endl;
//    }
//    cout << deal;
    
    cout << endl;
    for(int i = 0; i<deal; i++){
            Board.Gens[0].Hand[i] = Board.Deck[i];
            Board.Gens[1].Hand[i] = Board.Deck[deal+i];
    }
    
//    for(int i =0; i<deal; i++){
//        if(Board.Gens[0].Hand[i].wild == true)
//            cout << "WildCard" << endl;
//        else
//            cout << "Nation #" << Board.Gens[0].Hand[i].nation << " / # of Armies: " << Board.Gens[0].Hand[i].armies << endl;
//    }
//    cout << endl << endl<< endl << endl;
//    for(int i = 0; i<deal; i++){
//        if(Board.Gens[1].Hand[i].wild == true)
//            cout << "WildCard" << endl;
//        else
//            cout << "Nation #" << Board.Gens[1].Hand[i].nation << " / # of Armies: " << Board.Gens[1].Hand[i].armies << endl;
//    }
    armset(Board.Gens[0].Hand, Board.Gens[1].Hand, Board.World, deal-1);
//    for (int i = 0; i<contmax-2; i++){
//        cout << "Nation #" << Board.World[i].name << " # of red armies: " << Board.World[i].redarmy << " # of blue armies: ";
//        cout << Board.World[i].bluarmy << " # of white armies: " << Board.World[i].whtarmy << endl;
//    }
    return Board;
}
void binwrte(char *a, string file){
    ofstream outFile;
    outFile.open(file, ios::out | ios::binary);
    outFile.write(reinterpret_cast<char*>(a), sizeof(a));
    outFile.close();
}
bool victst(string file, int a){
    ifstream inFile;
    const int NUMPLRS = 2;
    char * n = new char[NUMPLRS];
    bool tkdwn = false;
    inFile.open(file, ios::in | ios::binary);
    inFile.read(reinterpret_cast<char *>(n), sizeof(n));
    inFile.close();
    if(n[1] == a){
        tkdwn = true;
    }
    return tkdwn;
}
void prnnat(Nation * A, int n){
    int width = 24;
    for (int i = 0; i<n; i++){
        cout <<setw(width)<< "Nation #" << A[i].name << " / Controlled by: ";
        if(A[i].bluarmy>A[i].redarmy){
            cout << "You; with " << A[i].bluarmy << " armies" << endl;
            
        }
        if(A[i].bluarmy<A[i].redarmy){
            cout << "Gen. Si-Piyu with " << A[i].redarmy << " armies" << endl;
        }
    }
}
char * hqset (Nation* A, int n){
    prnnat(A,n);
    const int NPLAYER = 2;
    int halfdek = n/2;
    int j = 0;
    int randNtn;
    char *hq = new char[NPLAYER];
    int rednat[halfdek];
    cout << "Which Nation would you like as your HQ?";
    cin >> hq[0];
    for(int i = 0; i<n; i++){
        if(A[i].redarmy>0){
            rednat[j] = A[i].name;
            j++;
        }
    }
    randNtn = rand()%halfdek;
    hq[1]=A[rednat[randNtn]].name;
    return hq;
    
}
void armplc(Nation * A, Player B, Player R , int n){
    int halfdek = n/2;
    int j = 0;
    int k = 0;
    bool trublu = false;
    int cChoice, nArm;
    int redNat[halfdek];
    int bluNat[halfdek];
    for( int i =0; i<n; i++){
        if(A[i].redarmy>0){
            redNat[j] = A[i].name;
            j++;
        }
    }
    do{
        A[redNat[k]].redarmy++;
        R.armies--;
        k++;
        if(k == halfdek){
            k=0;
        }
    }while(R.armies>0);
    j=0;
    k=0;
    prnnat(A, n);
    cout << "You Have "<<B.armies<<" Armies to Place" << endl;
    cout << "Enter the number of the country you control in which you wish to place armies." << endl;
    cout << "Then, enter the number of armies you wish to place in that country." << endl;
    cout << "I.E. If you wanted to put 2 armies in country number 11 you would type (11 'space' 2 'enter')" << endl;
    cout << "Army placements are permanent" << endl;
    for(int i =0; i<n; i++){
        if(A[i].bluarmy>0){
            bluNat[j] = A[i].name;
            j++;
        }
    }
    for(int i =0; i<halfdek; i++){
        cout << bluNat[i] << endl;
    }
    do{
        cout << "You have " << B.armies << " left to place" << endl;
        do{
            cin >> cChoice >> nArm;
            for(int i = 0; i<halfdek; i++){
                if(bluNat[i] == cChoice){
                    trublu = true;
                }
            }
            if(nArm > B.armies){
                trublu = false;
            }
            if(!trublu){
                cout << "You do not control that country, or you do not have that many armies on reserve." << endl;
                cout << "Enter a different country or number of armies." << endl;
            }
        }while(!trublu);
        A[cChoice].bluarmy += nArm;
        B.armies -= nArm;
    }while(B.armies>0);
    prnnat(A, n);
}
void turn(int, Gamebrd);
bool adjtest (int a, int b){
    const int NUM = 14;
    int prime[NUM] = {1,2,3,5,7,11,13,17,19,23,29,31,37,41};
    
    bool adj = false, prime1 = false, prime2 = false;
    
    for(int i = 0; i<NUM; i++){
        if(a == prime[i]){
            prime1 = true;
        }
        if(b == prime[i]){
            prime2 = true;
        }
    }
    if(a == 0 || b == 0){
        adj = true;
    }
    else{
        if(a%2 == b%2 || a%3 == b%3 || a%5 == b%5){
            adj == true;
        }
        else if(prime1 && prime2){
            adj = true;
        }
    }
    return adj;
}
int battle(Nation * A, Player B, Player C, int n){
    const int MAXATTK = 3, MAXDFND = 2;
    bool allow = false;
    int bluCont = 0;
    int redCont = 0;
    int j = 0;
    int base, targ, winner, bLoss=0, rLoss=0, count = 0;;
    int choice, defen;
    int halfdek = n/2;
    int def[MAXDFND];
    int att[MAXATTK];
    int bluNat[n];
    int redNat[n];
    for(int i=0; i<n; i++){
        if(A[i].bluarmy>0){
            bluCont ++;
        }
        if(A[i].redarmy>0){
            redCont++;
        }
    }
    cout << bluCont << endl << redCont << endl << endl;
    for(int i = 0; i<n; i++){
        if(A[i].bluarmy>0){
            bluNat[j] = A[i].name;
            j++;
        }
    }
    j = 0;
    for(int i = 0; i<n; i++){
        if(A[i].redarmy>0){
            redNat[j] = A[i].name;
            j++;
        }
    }
    
    
    
    do{
        cout << "Which Nation do you wish to attack from? :";
        cin >> base;
        for(int i=0; i<bluCont; i++){
            if(base == bluNat[i]){
                allow = true;
            }
        }
        if(!allow){
            cout << "That is not a country you control" << endl;
        }
    }while(!allow);
    
    
    do{
        cout << "Enter the number of armies you wish to attack with: ";
        cin >> choice;
        if(choice > A[base].bluarmy || (A[base].bluarmy - choice) == 0 || choice > 3){
            allow = false;
            cout << "You do not have that many armies to move" << endl;
            cout << "REMEMBER, You must have at least 1 army on a territory you control, and you may not use more than 3 armies" << endl;

        }
    }while(!allow);
    

     do{
        cout << "Which Nation do you wish to attack? :";
        cin >> targ;
        for(int i=0; i<redCont; i++){
            if(targ == redNat[i]){
                allow = true;
            }
        }
        if(!allow){
            cout << "That is not a country General Si Piyu controls" << endl;
        }
        allow = adjtest(base, targ);
        if(!allow){
            cout << "These territories are not adjacent" << endl;
        }
    }while(!allow);
    cout << "You rolled: ";
    for(int i = 0; i<choice; i++){
        att[i] = dieroll();
        cout << att[i] << ", ";
    }
    if(A[targ].redarmy == 1){
        defen = 1;
    }
    else{
        defen = 2;
    }
    cout << "Your opponent rolled: ";
    for(int i=0; i<defen; i++){
        def[i] = dieroll();
        cout << def[i] << ", ";
    }
    for(int i = 0; i<MAXDFND; i++){
        for(int j=0; j<MAXATTK; j++){
            if(def[i] < att[j]){
                count++;
            }
        }
        if(count == 3){
            rLoss++;
        }
    }
    count = 0;
    for(int i = 0; i<MAXATTK; i++){
        for(int j=0; j<MAXDFND; j++){
            if(def[i] >= att[j]){
                count++;
            }
        }
        if(count == 2){
            bLoss++;
        }
    }
    if(rLoss > bLoss){
        winner = 1;
    }
    if(bLoss < rLoss){
        winner = 0;
    }
    return winner;
}
void trdin (Card*, Player);

void destroy(Card * A, Nation * D, Player * E, char * f, const int N){
    delete []A;
    delete []D;
    for(int i=0; i<N; i++){
        delete []E[i].Hand;
    }
    delete []f;
}