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

void PrintNumberInReversed (int Number) {

    int Remainder = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        cout << Remainder << endl;
    }
}
int main() {

    PrintNumberInReversed(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}