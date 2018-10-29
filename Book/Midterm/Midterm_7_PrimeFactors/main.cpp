/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on October 28th, 2018 2:22pm
 * Purpose:  Prime Factors
 */
/*7) Factor an input integer into it's prime numbers.  Create a 
structure to hold the array of prime numbers.  Any number between
[2,10000] will be a valid number to check for prime factors.

struct Prime{
	unsigned char prime;
	unsigned char power;
};
struct Primes{
	Prime *prime;
	unsigned char nPrimes;
};
Output the number and it's primes -> 120 = 2^3 * 3^1 * 5^1
So create a function 
Primes *factor(int);-> Input an integer, return all prime factors
void prntPrm(Primes *); -> Output all prime factors
 */
// System Libraries Here
#include <iostream>
using namespace std;

// User Libraries Here
#include "PrimeArrStruct.h"
#include "PrimeStruct.h"
// Global Constants Only, No Global Variables
// Like PI, e, Gravity, or conversions

// Function Prototypes Here

// Program Execution Begins Here
int main(int argc, char** argv) {
    // Declare all Variables Here
    const int NPLTHUN = 25;
    int number;
    bool one;
    Primes prmcont;
    unsigned char prmnum[NPLTHUN] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    prmcont.primes = new Prime[NPLTHUN];

    // Input or initialize values Here
        for(int i = 0; i < NPLTHUN; i++){
        prmcont.primes[i].prime = prmnum[i];
        prmcont.primes[i].power = 0;
    }
    cout << "Enter a number between 2 and 10000: ";
    cin >> number;
    
    // Process/Calculations Here

        for(int i = 0; i<NPLTHUN; i++){
            do{
                one = true;
                if(number % prmcont.primes[i].prime == 0){
                    number /= prmcont.primes[i].prime;
                   prmcont.primes[i].power++;
                   one = false;
                }
            }while(!one);
        }

    // Output Located Here
    cout << number << "-> ";
    for(int i=0; i<NPLTHUN; i++){
        if(prmcont.primes[i].power != 0)
            cout << (int)prmcont.primes[i].prime << "^" << (int)prmcont.primes[i].power << " * ";
    }

    // Exit
    return 0;
}
