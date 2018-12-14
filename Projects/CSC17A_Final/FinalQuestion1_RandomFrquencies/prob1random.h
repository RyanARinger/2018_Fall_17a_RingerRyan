/* 
 * File:   prob1random.h
 * Author: Ryan Ringer
 * Created on December 13, 2018 11:37 AM
 * Purpose: 
 */

#ifndef PROB1RANDOM_H
#define PROB1RANDOM_H

class P1Rand
{
	private:
		char *set;      //The set of numbers to draw random numbers from
		char  nset;     //The number of variables in the sequence
		int  *freq;     //Frequency of all the random numbers returned
		int   numRand;  //The total number of times the random number function is called
	public:
		P1Rand(const char,const char *);	  //Constructor
		~P1Rand(void);				  //Destructor
		void setArrs(const char, const char *);		  //Sets the set and frequency arrays
		void setNset(char n) { nset = n; }	  //Sets the number of variables in the sequence
		void setNRand() { numRand = 0; }	  //Initializes the numRand variable
		char randFromSet(void);                   //Returns a random number from the set
		int *getFreq(void) const;                 //Returns the frequency histogram
		char *getSet(void) const;                 //Returns the set used
		int getNumRand(void) const;               //Gets the number of times randFromSet has
		                                          //been called
};

#endif /* PROB1RANDOM_H */

