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
    PrintMxArray(MxArray);
    
    return 0;
}