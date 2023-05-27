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

void ReversNumber (int Number) {

    string Reverse;
    int Remainder = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        Reverse += to_string(Remainder);
    }
    cout << Reverse << endl;
}
int main() {

    ReversNumber(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}