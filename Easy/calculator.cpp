#include <iostream>
using namespace std;

struct stcalculator
{
    float Number1;
    float Number2;
    char sign;
};

stcalculator ReadNumberAndsign () {

    stcalculator Info;
    cout << "Please enter number -1- \n";
    cin >> Info.Number1;
    cout << "Please enter operation sign (+ - * /) \n"; 
    cin >> Info.sign;
    cout << "Please enter number -2- \n";
    cin >> Info.Number2;

    return Info;
}

float CalculatInfo(stcalculator Info) {

    if (Info.sign == '+') {
        return Info.Number1 + Info.Number2;
    }
    else if (Info.sign == '-') {
        return Info.Number1 - Info.Number2;
    }
    else if (Info.sign == '*') {
        return Info.Number1 * Info.Number2;
    }
    else if (Info.sign == '/') {
        return Info.Number1 / Info.Number2;
    }
    else {
        return 0;
    }
}

void PrintResult(float Result) {

    cout << " \n The result is " << Result << endl;
}
int main() {

    PrintResult(CalculatInfo(ReadNumberAndsign()));
    return 0;
}