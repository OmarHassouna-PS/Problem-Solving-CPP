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

void MultiplyMx (short Results[3][3], short MxArray1[3][3], short MxArray2[3][3], short Rows, short Cols) {

    for (size_t i = 0; i < Rows; i++)
    {
        for (size_t j = 0; j < Cols; j++)
        {
            Results[i][j] = MxArray1[i][j] * MxArray2[i][j];
        }
    }

}

void PrintMxArray (short MxArray[3][3], short Rows, short Cols) {

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
           // cout << setw(3) << MxArray[i][j] << "\t";
            printf("%0*d\t", 2, MxArray[i][j]);
            
        }
        cout << "\n";
    }
}

int main() {
    
    srand((unsigned)time(0));
    short MxArray1[3][3], MxArray2[3][3], Results[3][3];

    FillMxArrayOfNumber(MxArray1, 3, 3);
    FillMxArrayOfNumber(MxArray2, 3, 3);
    MultiplyMx(Results, MxArray1, MxArray2, 3, 3);

    cout << "MxArray1:\n";
    PrintMxArray(MxArray1, 3, 3);
    
    cout << "\nMxArray2:\n";
    PrintMxArray(MxArray2, 3, 3);

    cout << "\nResults:\n";
    PrintMxArray(Results, 3, 3);



    
    
    return 0;
}