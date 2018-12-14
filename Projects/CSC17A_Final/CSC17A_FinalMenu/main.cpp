/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on December 13, 2018 9:10 PM
 * Purpose: 
 */


//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Employee.h"
#include "prob1random.h"
#include "SavingsAccount.h"
#include "Prob2Sort.h"
#include "Prob3Table.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
//Program Execution Begins Here

int main(int argc, char** argv) {
    // Random numer seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Constant Variable

    //Declare all Variables Here
    int choice;
    //Input or initialize values Here

    //Process/Calculations Here
    do{
	cout << "Please enter the problem you wish to view" << endl;
	cout << "Problem 1 (1)" << endl;
	cout << "Problem 2 (2) (not functional, file included in final folder)" << endl;
	cout << "Problem 3 (3) (not functional, file included in final folder)" << endl;
	cout << "Problem 4 (4)" << endl;
	cout << "Problem 5 (5)" << endl;
	cin >> choice;

        switch (choice){
            case(1): cout << endl; problem1(); break;
            case(2): cout << endl; problem2(); break;
            case(3): cout << endl; problem3(); break;
            case(4): cout << endl; problem4(); break;
            case(5): cout << endl; problem5(); break;
//            case(6): cout << endl; problem6(); break;
            case(7): exit(0);
            default: cout << "Invalid Choice";
        }
    }while (choice !=7);
    //Output Located Here

    //Exit

    return 0;
}


void problem1(){
     
    char n=5;
    char rndseq[]={18,33,56,79,125};
    int ntimes=100000;
    P1Rand a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
	    a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
	    cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;

//    delete[] x;
//    delete[] y;
}

void problem2(){
    
    cout << "I was not successful in getting this problem working" << endl;
    cout << "Attempted Project file is included" << endl << endl;
//    cout<<"The start of Problem 2, the sorting problem"<<endl;
//    Prob2Sort<char> rc;
//    bool ascending=true;
//    ifstream infile;
//    infile.open("data.txt",ios::in);
//    char *ch2=new char[10*16];
//    char *ch2p=ch2;
//    
//    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
//    infile.close();
//    cout<<endl;
//    cout<<"Sorting on which column"<<endl;
//    int column;
//    cin>>column;
//    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
//    for(int i=0;i<10;i++)
//    {
//	    for(int j=0;j<16;j++)
//	    {
//		    cout<<zc[i*16+j];
//	    }
//    }
//    delete []zc;
//    cout<<endl;
}

void problem3(){
    cout << "I was not successful in getting this problem working" << endl;
    cout << "Attempted Project file is included" << endl << endl;
    
//    cout<<"Entering problem number 3"<<endl;
//    int rows=5;
//    int cols=6;
//    string fileName = "data.txt";
//    ifstream inFile;
//    inFile.open(fileName, ios::in);
//
//
//    int ** table = new int*[cols];
//    for(int i=0; i<cols; i++){
//	table[i] = new int[rows];
//    }
//
//    for(int i=0; i<rows; i++){
//	for(int j=0; j<cols; j++){
//	    inFile >> table[i][j];
//	}
//    }
//    Prob3TableInherited<int> tab(table,rows,cols);
//    const int *naugT=tab.getTable();
//    for(int i=0;i<rows;i++)
//    {
//	    for(int j=0;j<cols;j++)
//	    {
//		    cout<<naugT[i*cols+j]<<" ";
//	    }
//	    cout<<endl;
//    }
//    cout<<endl;
//    const int *augT=tab.getAugTable();
//    for(int i=0;i<=rows;i++)
//    {
//	    for(int j=0;j<=cols;j++)
//	    {
//		    cout<<augT[i*(cols+1)+j]<<" ";
//	    }
//	    cout<<endl;
//    }
}

void problem4(){
    SavingsAccount acct(-300);

    for(int i=1;i<=10;i++) {
        acct.transaction((float)(rand()%500)*(rand()%3-1));
    }
    
    acct.toString();
    
    cout<<"Balance after 7 years given 10% interest = "
            << acct.total((float)(0.10),7) << endl;
    
    cout<<"Balance after 7 years given 10% interest = "
            << acct.totalRecursive((float)(0.10),7)
            <<" Recursive Calculation " << endl;
}
    
void problem5(){
    // i was getting some warnings because i was sending string literals instead of
    // char[] so i made these to mitigate the warnings
    char name1[5]  = "Mark";
    char name2[5]  = "Mary";
    char title1[5]  = "Boss";
    char title2[4] = "VP";
    
    Employee Mark(name1,title1,215.50); 
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.calculatePay(Mark.setHourlyRate(20.0),
                      Mark.setHoursWorked(25));
    Mark.toString();
    Mark.calculatePay(Mark.setHourlyRate(40.0),
                      Mark.setHoursWorked(25));
    Mark.toString();
    Mark.calculatePay(Mark.setHourlyRate(60.0),
                      Mark.setHoursWorked(25));
    Mark.toString();

    Employee Mary(name2,title2,50.0);
    Mary.toString();
    Mary.calculatePay(Mary.setHourlyRate(50.0),
                      Mary.setHoursWorked(40));
    Mary.toString();
    Mary.calculatePay(Mary.setHourlyRate(50.0),
                      Mary.setHoursWorked(50));
    Mary.toString();
    Mary.calculatePay(Mary.setHourlyRate(50.0),
                      Mary.setHoursWorked(60));
    Mary.toString();
}