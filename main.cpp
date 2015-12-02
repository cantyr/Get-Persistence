// main.cpp

// Author: Ryan Canty

// Date: 10/28/15

// Course: CSC1610

// Description: This file takes a user-inputted postive, non-zero integer and then
// outputs the perspective of that integer as well as each product of the digits, repeated,
// until a single integer is left.

// Input: One user-defined integer collected from the standard input stream
// (keyboard).

// Output: The products of the digits of the integer, repeated until a single digits remains,
// and a sentence telling the user the perspective of the number.

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <cassert>

using namespace std;

int getProductOfDigits( int ); //Prototype
int getPersistence( int ); //Prototype

int main() 
{
    int userNum; //Integer that will store the user inputted number
    do
    {
        cout << "Please give me a non-negative integer: ";
        cin >> userNum; //Store user-inputted number
        if(userNum < 0)
        {
            cout << "ERROR: Only non-negative integers please." << endl;
        }
        cout << endl;
    }
    while(userNum < 0);
    
    int persistence; //Integer that will hold the persistence of userNum
    persistence = (int)getPersistence(userNum); //Set persistence equal to the persistence of userNum
                                                //Also calls getPersistence using userNum to display 
                                                //the products
    cout << "The persistence of " << userNum << " is " << persistence << ".";  //Displays the 
                                                                               //persistence of 
    return 0;                                                                  //userNum
    
}
//Description: Takes in a user-inputted integer outputs the product of the digits of the number
//repeatedly until a single digit is outputted.  Also returns an integer that displays the 
//persistence of userNum
//Precondition: userNum must be a positive, non-zero number (greater than 0)
//Postcondition: returns an integer that displays the persistence of userNum as well as each
//product of all of the digits repeatedly, separated by arrows.
int getPersistence( int userNum )
{
    assert(userNum > 0);
    int persistence = 0; //Integer that will represent the persistence of userNum (How many times
                         //digits are multiplied together)
    cout << userNum; //Output the user-inputted number to begin.
    while( userNum > 9) //Go until userNum is a single integer
    {
        cout << " -> "; //Output arrow in between each product of the digits
        int product = 1; //Integer that will be multiplied by each digit of userNum
        for( int i = userNum; i > 0; i/= 10 )
        {
            product *= (userNum % 10); //product is equal to itself times the right most digit of
            userNum /= 10; //Drop right most digit                                      //userNum
        }
        userNum = product; //Set userNum equal to the product, so when it goes back into the loop
        cout << product; //Output the product                                        //it changes
        persistence++; //Increment persistence by 1
    }
    cout << endl; //Output blank line
    return persistence; //return the number of times it took to get to a single digit (persistence)
}

