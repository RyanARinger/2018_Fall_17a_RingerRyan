/* 
 * File:   Prob3Table.h
 * Author: Ryan Ringer
 * Created on December 13, 2018 3:16 PM
 * Purpose: 
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

template<class T>
class Prob3Table
{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		T *rowSum;                                //RowSum array
		T *colSum;                                //ColSum array
		T *table;                                 //Table array
		T grandTotal;                             //Grand total
		void calcTable(void);                     //Calculate all the sums
	public:
		Prob3Table(T *,int,int);               //Constructor then Destructor
		virtual ~Prob3Table();
		virtual void setTable(T * t){ table = t; }
		virtual void setRow(int r){ rows = r; }
		virtual void setCol(int c){ cols = c; }
		void addRows();
		void addCols();
		const T *getTable(void){return table;};
		const T *getRowSum(void){return rowSum;};
		const T *getColSum(void){return colSum;};
		T getGrandTotal(void){return grandTotal;};
};


#endif /* PROB3TABLE_H */

