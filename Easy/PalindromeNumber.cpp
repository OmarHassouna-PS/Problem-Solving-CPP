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

    int Remainder = 0; 
    long long Number2 = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        Number2 = (Number2 * 10) + Remainder;
    }
    cout << Number2;
    return Number2;
}

bool IsPalindromeNumber (int Number) {

    return Number == ReverseNumber(Number);

}

int main() {

    if (IsPalindromeNumber(ReadPositiveNumber("Please enter a positive number?"))) 
        cout << "Yes , it is a Palindrome number." << endl;
    else 
        cout << "No , it is Not a Palindrome number." << endl;
 
    return 0;
}