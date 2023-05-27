#include <iostream>
#include <string>
#include <cstring>

using namespace std;



string ReadPositiveNumber (string Message) {

    string Number;
    do {

        cout << Message << endl;
        cin >> Number;
    } while (stoi(Number) <= 0);
    return Number;
}

int CountNumberInReversed (string Number) {

    int CountNumber = 0;
    
    while (Number[CountNumber] != '\0')
    {
        CountNumber++;
    }
    return CountNumber;
}

void PrintNumberInReversed (string Number, int CountNumber) {

    for (size_t i = 1; i <= CountNumber; i++)
    {
        cout << Number[CountNumber - i] << endl;
    }
    
}
int main() {
    string Number = ReadPositiveNumber("Please enter a positive number?");
    PrintNumberInReversed(Number ,CountNumberInReversed(Number));
    return 0;
}