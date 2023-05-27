#include <iostream>
#include <math.h>
using namespace std;
enum enPrimeNotPrim {Prime = 1, NotPrim = 2};

float ReadPositiveNumber (string Message) {

    float Number = 0;
    do {

        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

enPrimeNotPrim CheckPrime(int Number) {

    int M = round(Number / 2);

    for (size_t i = 2; i <= M; i++) {
        
        if (Number % i == 0)
            return enPrimeNotPrim::NotPrim;
    }
    
    return enPrimeNotPrim::Prime;
}

void PrintNumberType (int Number) {

    switch (CheckPrime(Number))
    {
    case enPrimeNotPrim::Prime:
        cout << "The number is prime\n";
        break;
    case enPrimeNotPrim::NotPrim:
    cout << "the number is not prime";
    }
}

int main() {

    PrintNumberType(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}