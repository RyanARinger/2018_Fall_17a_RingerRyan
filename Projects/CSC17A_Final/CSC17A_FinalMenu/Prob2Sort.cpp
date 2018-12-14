/* 
 * File:   Prob2Sort.cpp
 * Author: Ryan Ringer
 * Created on December 13, 2018 1:44 PM
 * Purpose: 
 */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "Prob2Sort.h"

template<class T>
Prob2Sort<T>::Prob2Sort(){
    index=nullptr;
}

template<class T>
Prob2Sort<T>::~Prob2Sort(){
    delete []index;
}

template<class T>
T * Prob2Sort<T>::sortArray( T* arr, int sz, bool asc){
    T str;
    
    if(asc){
	for(int i=0; i<sz; i++){
	    for(int j=0; j<sz; j++){
		if(arr[i] > arr[j] && i!=j){
		    str = arr[j];
		    arr[j] = arr[i];
		    arr[i] = str;
		}
	    }
	}
    }
    else if(!asc){
	for(int i=0; i<sz; i++){
	    for(int j=0; j<sz; j++){
		if(arr[i] < arr[j] && i!=j){
		    str = arr[j];
		    arr[j] = arr[i];
		    arr[i] = str;
		}
	    }
	}
    }
    index = arr;
    return arr;
}

template<class T>
T * Prob2Sort<T>::sortArray(T* arr, int row, int col, int cChoice, bool asc){
    
    T str;
    
    if(asc){
	for(int i=0; i<row; i++){
	    for(int j=0; j<row; j++){
		if(arr[i][cChoice] > arr[j][cChoice] && i!=j){
		    str = arr[j];
		    arr[j] = arr[i];
		    arr[i] = str;
		}
	    }
	}
    }
    else if(!asc){
	for(int i=0; i<row; i++){
	    for(int j=0; j<row; j++){
		if(arr[i][cChoice] < arr[j][cChoice] && i!=j){
		    str = arr[j];
		    arr[j] = arr[i];
		    arr[i] = str;
		}
	    }
	}
    }
    
    index = arr;
    return arr;
}
