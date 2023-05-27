#include <iostream>
#include <math.h>

using namespace std;

short ReadPositiveNumber (string Message) {

    short Number = 0;
    do {

        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

bool CheckPerfectNumber (short Number) {

    short Sum = 0;
    for (size_t i = 1; i <= (Number / 2); i++)
    {
        if (Number % i == 0)
            Sum += i;      
    }
    if (Sum == Number)
        return true;
    return false;

    // or return Number == Sum
}

void PrintPerfectNumber (short Number) {
    
    if (CheckPerfectNumber(Number))
        cout << Number << " is perfect number\n";
    else
        cout << Number << " is not perfect number\n";
}

int main() {

    PrintPerfectNumber(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
} 