/* 
 * File:   Prob3TableInherited.cpp
 * Author: Ryan Ringer
 * Created on December 13, 2018 4:58 PM
 * Purpose: 
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include"Prob3TableInherited.h"

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(T * arr, int r, int c){
    
    this->setTable(arr);
    this->setCol(c);
    this->setRow(r);
    this->addCols();
    this->addRows();
    this->calcTable();
    this->setAugTable();
}

template<class T>
void Prob3TableInherited<T>::setAugTable(){
    this->augTable = new T[this->cols+1];
    for(int i=0; i<=this->cols; i++){
	this->augTable[i] = new T[this->rows+1];
    }
    for(int i=0; i<this->cols; i++){
	this->augTable[i][this->rows+1] = this->colSum[i]; 
    }
    for(int i=0; i<this->rows; i++){
	this->augTable[this->cols+1][i] = this->rowSum[i];
    }
    
    this->augTable[this->cols+1][this->rows+1] = this->grandTotal;
}