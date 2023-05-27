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
            MxArray[i][j] =  Math::RandomNumber(1, 5);
        }
    }
}

void Rows (short MxArray[3][3], short Rows, short length) {

    for (size_t i = 0; i < length; i++)
    {
        printf("%0*d\t", 2, MxArray[Rows][i]);
    }
        cout << "\n";
}

void Cols (short MxArray[3][3], short Cols, short length) {

    for (size_t i = 0; i < length; i++)
    {      
        printf("%0*d\t", 2, MxArray[i][Cols]);
    }
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

    cout << "MxArray:\n";
    PrintMxArray(MxArray, 3, 3);

    cout << "\nMiddle Row of Matrix1 is:\n";
    Rows(MxArray, 1, 3);

    cout << "\nMiddle Row of Matrix2 is:\n";
    Cols(MxArray, 1, 3);
    
    
    return 0;
}