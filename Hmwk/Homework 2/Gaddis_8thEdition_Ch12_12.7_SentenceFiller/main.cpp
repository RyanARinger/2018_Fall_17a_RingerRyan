/* 
 * File:   main.cpp
 * Author: Ryan RInger
 * Created on September 24th, 2018
 * Purpose:  Sentence Filter 12.7
 */

//System Libraries Here
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

int counter(string); // counts number of characters
char* read(string,int); // reads in characters to a char array
char * filter(char*, int); // capitalizes and lowercases needed values
void write (string, char*, int); // write to file
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    string file1;   // file to read from
    string file2;   // file to write on
    int charcnt;    // number of characters in the file
    char * charray;
    char * filtarr;
    //Input or initialize values Here
    cout << "Enter the name of the file to read: ";
    getline (cin, file1, '\n');
    cout << "Enter the name of the file to write to: ";
    getline (cin, file2, '\n');
    charcnt = counter(file1); // number of characters
    //Process/Calculations Here
    charray = read(file1,charcnt);
    filtarr = filter(charray, charcnt);
    write(file2, filtarr, charcnt);
    //Output Located Here
        // no output
    //Exit
    return 0;
}
int counter(string file1){
    int count = 0;
    char x;
    ifstream inFile;
    inFile.open(file1.c_str());
    
    while (inFile >> noskipws >> x){
        count ++;
    }
    inFile.close();
    //cout << count << endl;        //total character output(debug)
    return count;
}
    
char* read(string file1, int count){
    ifstream inFile;
    
    char* c = new char[count];
    
    inFile.open(file1.c_str());
    
    for(int i=0; i<count; i++){
        inFile >> noskipws >> c[i];
        //cout << (int)c[i] << " ";     // outputs ascii values(debug)
    }
    inFile.close();
    return c;
}

char * filter(char* c, int count){
    char* nc = new char[count];
    bool period = true; // tester for start of a new sentence
    int asc;    // variable for ascii value
    for (int i=0; i<count; i++){
        asc = (int)c[i];
//        cout << asc << " ";
        if (period == true){
            if(asc > 96 && asc < 123){
                asc -= 32;
                //cout << asc << " ";           // commented cout's for displaying ascii values for debugging
                nc[i] = (char)asc; 
                period = false;
            }// end of capitalization
            else{
                nc[i]= c[i];
               // cout << asc << " ";
                period = false;
            }
        }// end of period test
        else{
            if(asc > 65 && asc < 91){
                asc += 32;
                //cout << asc << " ";
                nc[i] = (char)asc;
                period = false;
            }
            else if(asc == 46){
                period = true;
                //cout << asc << " ";
                nc[i]=(char)asc;
            }
            else{
                nc[i]=c[i];
                //cout << asc << " ";
                period = false;
            }
        }// end of if's in 'for loop'
    }
    return nc;
}

void write(string file2, char* c, int count){
    ofstream outFile;
    outFile.open(file2.c_str());
    
    for (int i=0; i<count; i++){
        outFile << c[i];
    }
    outFile.close();
}