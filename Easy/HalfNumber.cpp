#include <iostream>
using namespace std;

int GetNumber() {

    int Number = 0;
    cout << "Please enter yor number ? \n";
    cin >> Number;
    return Number;
}

float HalfNumber(float Number) {

    return (float) Number / 2;
}

void PrintResults(float HalfNumber) {

    cout << "yor half number is " << HalfNumber << endl;
}
int main() {

    PrintResults(HalfNumber(GetNumber()));
    return 0;
}