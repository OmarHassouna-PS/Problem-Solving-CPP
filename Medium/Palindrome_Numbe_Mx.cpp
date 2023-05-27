#include <iostream>
#include <iomanip>

#include "InputLib.h"
#include "Mathlib.h"

using namespace std;

bool IsPalindromeMx (short MxArray[3][5], short Rows, short Cols) {

    for (size_t i = 0; i < Rows; i++)
    {
        for (size_t j = 0; j < Cols / 2; j++)
        {
            if (MxArray[i][j] != MxArray[i][Cols - j - 1])
                return false;
        }
    }
    return true;
}

void PrintMxArray (short MxArray[3][5], short Rows, short Cols) {

    for (size_t i = 0; i < Rows; i++)
    {
        for (size_t j = 0; j < Cols; j++)
        {
           cout << setw(3) << MxArray[i][j] << "\t";
        }
        cout << "\n";
    }
}


int main() {

    srand((unsigned)time(0));
    short MxArray[3][5] = { {1,2,1,2,1}, {7,3,3,3,7}, {9,8,7,8,9} };

    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMxArray(MxArray, 3, 5);

    if (IsPalindromeMx(MxArray, 3, 5))
        cout << "\nYes is palindrome";
    else
    cout << "\nNo is Not palindrome";

    return 0;
}