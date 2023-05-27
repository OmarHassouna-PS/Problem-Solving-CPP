#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int ReadPositiveNumber (string Message) {

    int Number = 0;
    do {

        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int FrequencyNumber (int Number, int Frequency) {

    int Remainder = 0, Count = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        if (Frequency == Remainder)
            Count++;
    }
    return Count;
}

int main() {
    int Number = ReadPositiveNumber("Please enter a positive number?");
    int Frequency = ReadPositiveNumber("Please enter a Frequency number?");
    cout << "Digit " << Frequency << " Frequency " << "is " << FrequencyNumber(Number, Frequency) << " Time(s)" << endl;
    

    return 0;
}