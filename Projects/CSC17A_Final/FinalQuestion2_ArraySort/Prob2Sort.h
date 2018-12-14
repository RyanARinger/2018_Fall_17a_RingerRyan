/* 
 * File:   Prob2Sort.h
 * Author: Ryan Ringer
 * Created on December 13, 2018 12:17 PM
 * Purpose: 
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H

#include <iostream>
#include <cstdlib>
using namespace std;



template<class T>
class Prob2Sort
{
	private:
		T *index;                                 //Index that is utilized in the sort
	public:
		Prob2Sort();                   //Constructor
		~Prob2Sort();              //Destructor
		T * sortArray(T*,int,bool);           //Sorts a single column array
		T * sortArray(T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
}; 

#endif /* PROB2SORT_H */

