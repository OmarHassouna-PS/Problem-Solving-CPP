#include <iostream>
#include <math.h>
using namespace std;

float ReadPositiveNumber (string Message) {

    float Number = 0;
    do {

        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

float CalRemainder(float TotalBill) {

    TotalBill = TotalBill * 1.1;
    TotalBill = TotalBill * 1.50;
    return TotalBill;
}

void PrintResult(float Result) {

    cout << " \n The rest is " << Result << endl;
}

int main() {
    float TotalBill = ReadPositiveNumber("Please enter Total Bill ?");

    PrintResult(CalRemainder(TotalBill));
    return 0;
}