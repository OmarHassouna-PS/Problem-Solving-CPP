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

    for (size_t i = Number; i >= 1 ; i--)
    {
        for (size_t j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;

    }

/*     {
        for (size_t j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
        1
        22
        333
    }
  
 */}
int main() {

    PrintNumber(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}