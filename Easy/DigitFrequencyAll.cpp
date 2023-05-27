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

void PrintFrequency (int Number) {

    for (size_t i = 0; i < 10; i++)
    {
        int DigitFrequency = FrequencyNumber(Number, i);

            if (DigitFrequency > 0)
            {
                cout << "Digit " << i << " Frequency " << "is " <<
                DigitFrequency << " Time(s)" << endl;
            }
    }
}



int main() {

    PrintFrequency(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}