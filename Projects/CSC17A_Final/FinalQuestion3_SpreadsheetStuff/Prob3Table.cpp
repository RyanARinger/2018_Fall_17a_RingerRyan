/* 
 * File:   Prob3Table.cpp
 * Author: Ryan Ringer
 * Created on December 13, 2018 4:39 PM
 * Purpose: 
 */

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

#include "Prob3Table.h"

template<class T>
Prob3Table<T>::Prob3Table(T* t, int r, int c){
    this->table = t;
    this->rows = r;
    this->cols = c;
}

template<class T>
Prob3Table<T>::~Prob3Table(){
    delete [] table;
    delete [] rowSum;
    delete [] colSum;
}

template<class T>
void Prob3Table<T>::calcTable(){
    T sum = 0;
    for(int i=0; i<rows; i++){
	sum += rowSum[i];
    }
    grandTotal = sum;
    
}

template<class T>
void Prob3Table<T>::addRows(){
       
    for (int i=0; i<rows; i++){
	for(int j=0; j<cols; j++){
	    rowSum[i] += table[i][j];
	}
    }
    
}

template<class T>
void Prob3Table<T>::addCols(){
    
    for (int i=0; i<cols; i++){
	for(int j=0; j<rows; j++){
	    colSum[i] += table[i][j];
	}
    }
}
