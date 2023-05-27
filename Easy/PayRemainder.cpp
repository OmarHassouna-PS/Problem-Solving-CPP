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

float CalRemainder(float TotalBill, float TotalCashPaid) {

    return TotalBill - TotalCashPaid;
}

void PrintResult(float Result) {

    cout << " \n The rest is " << Result << endl;
}

int main() {
    float TotalBill = ReadPositiveNumber("Please enter Total lBill?");
    float TotalCashPaid = ReadPositiveNumber("Please enter Total Cash Paid?");

    PrintResult(CalRemainder(TotalBill, TotalCashPaid));
    return 0;
}