#include <iostream>
using namespace std;
int ReadPositiveNumber (string Message) {

    int Number;
    do {

        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

void PrintNumber (int Number) {

     for (size_t i = (64 + Number); i >= 65; i--)
    {
        for (size_t j = 65; j <= i; j++)
        {
            cout << char(i);
        }
        cout << endl;
    } 
 
}
int main() {

    PrintNumber(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}