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

int ColsSum (short MxArray[3][3],short ColsNumber, short Cols) {

    int Sum = 0;
    for (short j = 0; j < Cols ; j++) {
        
        Sum += MxArray[j][ColsNumber];
    }
    return Sum;
}

void SumOfCols (short MxArray[3][3], short SumOfMxArray[3], short Rows, short Cols) {

    for (size_t i = 0; i < Rows; i++)
    {
        SumOfMxArray[i] = ColsSum(MxArray, i, Cols);
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

void PrintRowsSumMxArray (short MxArray[3], short Rows) {

    for (size_t i = 0; i < Rows; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << MxArray[i] << endl;
    }    
}

int main() {
    
    srand((unsigned)time(0));
    short MxArray[3][3];
    short SumOfMxArray[3];

    FillMxArrayOfNumber(MxArray, 3, 3);

    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMxArray(MxArray, 3, 3);

    cout << "\nThe following are the sum of each row in the matrix:\n";
    SumOfCols(MxArray, SumOfMxArray, 3, 3);
    PrintRowsSumMxArray(SumOfMxArray, 3);


    
    
    return 0;
}