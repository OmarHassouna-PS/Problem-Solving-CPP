#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int ReadPositiveNumber (string Message) {

    int Number;
    do {

        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

void PrintSumOfDigits (int Number) {

    int Sum = 0, Remainder = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        Sum += Remainder;
    }
    cout << Sum << endl;
}
int main() {

    PrintSumOfDigits(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}