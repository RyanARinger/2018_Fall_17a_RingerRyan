/* 
 * File:   main.cpp
 * Author: Ryan Ringer
 * Created on October 24th, 2018, 8:12 PM
 * Purpose:  Encryption
 */
/*4) A company wants to transmit data over the telephone, but they are 
concerned that their phones may be tapped. All of their data is 
transmitted as four-digit integers. However, they utilize the digits 
0,1,2,3,4,5,6,7 only. They have asked you to write a program that 
will encrypt their data so that it may be transmitted more securely.
Your application should read a four-digit integer with the numbers 
0 to 7 entered by the user in an input dialog and encrypt it as 
follows: Replace each digit by (the sum of that digit plus 5 modulus 8. 
Then swap the first digit with the third, and swap the second digit 
with the fourth. Then print the encrypted integer. Write a separate 
application that inputs an encrypted four-digit integer and decrypts 
it to form the original number.
Note:  sometimes errors occur and the digits 8, and 9 might appear.  
Detect this condition and flag the error.  Can't read in numbers 
individually.  All the digits must be read with one cin statement.*/

//System Libraries Here
#include <iostream>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
char encrypt(char);
char decrypt(char);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE = 4;
    char str;
    char a[SIZE];
    bool cont, de_en;
    do{
        cout << endl << "Encrypt(0) or Decrypt(1)? ";
        cin >> de_en;
        cout << endl << "Enter number: ";
        cin >> a;
        str = a[0];
        a[0] = a[2];
        a[2] = str;
        str = a[1];
        a[1] = a[3];
        a[3] = str;
        for(int i=0; i<SIZE; i++){
            if(!de_en){
                a[i] = encrypt(a[i]);
                cout << (int)a[i];
            }
            else{
                a[i] = decrypt(a[i]);
                cout << a[i];
            }
        }
        cout << endl << endl;
        cout << "Would you like to rerun? ((1)Yes or (0)No):";
        cin >> cont;
    }while(cont);
    //Exit
    
    return 0;
}
char encrypt(char a){
    char b = a;
    b +=5;
    b = b%8;
    return b;
}
char decrypt(char a){
    char b = a;
    //cout << b;
    if(b < '5'){
        b += 8;
    }
    b -= 5;
    return b;
}