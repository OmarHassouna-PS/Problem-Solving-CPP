#include <iostream>
#include <iomanip>

#include "InputLib.h"
#include "Mathlib.h"

using namespace std;

void FillMxArrayOfNumber (short MxArray[3][3], short Rows, short Cols) {
    
    for (size_t i = 0; i < Rows; i++)
    {
        for (size_t j = 0; j < Cols; j++)
        {
            MxArray[i][j] =  Math::RandomNumber(1, 100);
        }
    }
}

short Min (short MxArray[3][3], short Rows, short Cols) {

    short Min = MxArray[0][0];
    for (size_t i = 0; i < Rows; i++)
    {
        for (size_t j = 0; j < Cols; j++)
        {
            if (MxArray[i][j] < Min)
                Min  = MxArray[i][j];
        }
    }
    return Min;
}

short Max (short MxArray[3][3], short Rows, short Cols) {

    short Max = MxArray[0][0];
    for (size_t i = 0; i < Rows; i++)
    {
        for (size_t j = 0; j < Cols; j++)
        {
            if (MxArray[i][j] > Max)
                Max  = MxArray[i][j];
        }
    }
    return Max;
}

void PrintMxArray (short MxArray[3][3], short Rows, short Cols) {

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

    FillMxArrayOfNumber(MxArray, 3, 3);

    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMxArray(MxArray, 3, 3);

    cout << "\nMin is :" << Min(MxArray, 3, 3) << endl;
    
    cout << "\nMax is :" << Max(MxArray, 3, 3) << endl;

    return 0;
}