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
int ReverseNumber (int Number) {

    int Remainder = 0, Number2 = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        Number2 = Number2 * 10 + Remainder;
    }
    return Number2;
}

void PrintNumber (int Number) {

    int Remainder = 0, Num = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10; 
        cout << Remainder << endl;    
    }
    
}
int main() {

    PrintNumber(ReverseNumber(ReadPositiveNumber("Please enter a positive number?")));

    return 0;
}