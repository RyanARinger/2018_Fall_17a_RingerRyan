/* 
 * File:   Prob3TableInherited.h
 * Author: Ryan Ringer
 * Created on December 13, 2018 3:17 PM
 * Purpose: 
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H

#include "Prob3Table.h"

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
	protected:
		T *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(T *,int,int);          //Constructor
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		void setAugTable();
		const T *getAugTable(void){return augTable;}; 
};

#endif /* PROB3TABLEINHERITED_H */

