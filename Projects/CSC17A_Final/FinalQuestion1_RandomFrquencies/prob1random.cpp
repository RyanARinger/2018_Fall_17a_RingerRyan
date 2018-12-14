/* 
 * File:   prob1random.cpp
 * Author: Ryan Ringer
 * Created on December 13, 2018 11:38 AM
 * Purpose: 
 */

#include <iostream>
using namespace std;

#include "prob1random.h"

P1Rand::P1Rand(const char n, const char* s){
    this->setNset(n);
    this->setArrs(n, s);
    this->setNRand();
    
}

P1Rand::~P1Rand(){
    delete[] this->set;
    delete[] this->freq;
}

void P1Rand::setArrs(const char n, const char* s){
    this->set = new char[n];
    this->freq = new int[n];
    
    for(int i = 0; i < n; i++){
	this->set[i] = s[i];
    }
    
    for(int i = 0; i < n; i++){
	this->freq[i] = 0;
    }
}

char P1Rand::randFromSet(){
    int idx = rand()%this->nset;
    
    // Increment Frequency
    this->freq[idx] += 1;
    
    // Increment NumRand
    this->numRand += 1;
    // Return value
    return this->set[idx];
}

int * P1Rand::getFreq() const{
    return this->freq;
}

char * P1Rand::getSet() const{
    return this->set;
}

int P1Rand::getNumRand() const{
    return this->numRand;
}