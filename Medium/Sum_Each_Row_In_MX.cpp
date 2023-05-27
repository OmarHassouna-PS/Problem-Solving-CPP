#include <iostream>
#include <iomanip>

#include "InputLib.h"
#include "Mathlib.h"

using namespace std;

void FillMxArrayOfNumber (short MxArray[3][3]) {
    
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            MxArray[i][j] =  Math::RandomNumber(1, 100);
        }
    }
}

int SumOfRow (short MxArray[3][3]) {

    for (size_t i = 0; i < 3; i++)
    {
        short Sum = 0;
        for (size_t j = 0; j < 3; j++)
        {
            Sum += MxArray[i][j];
        }
        cout << "Row " << i + 1 << " Sum = " << Sum << endl; 
    }
}

void PrintMxArray (short MxArray[3][3]) {

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cout << setw(3) << MxArray[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    
    srand((unsigned)time(0));
    short MxArray[3][3];

    FillMxArrayOfNumber(MxArray);

    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMxArray(MxArray);

    cout << "\nThe following are the sum of each row in the matrix:\n";
    SumOfRow(MxArray);
    
    return 0;
}