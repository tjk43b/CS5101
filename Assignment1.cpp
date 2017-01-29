/***********************************
* Programmed by: Tyler Kaufman     *
* File: Assignment1.cpp            *
* Date: 1/23/2017                  *
* Description: Fancy Hello World   *
************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    char userInput;
    cout << "Would you like to continue?\n" << endl;
    cout << "Type 'Y' to continue, or 'N' to exit: ";
    cin  >> userInput;
    cout << endl;

    while( userInput == 'Y' || userInput == 'y' )
    {
        cout << "Hello World!\n" << endl;
        cout << "Would you like to continue?\n" << endl;
        cout << "Type 'Y' to continue, or 'N' to exit: ";
        cin  >> userInput;
        cout << endl;
        if(userInput == 'N' || userInput == 'n')
        {
            cout << "Goodbye World!" << endl;
            exit(0);
        }
    }
    return 0;
}
