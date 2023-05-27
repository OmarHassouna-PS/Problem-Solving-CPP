#include <iostream>
using namespace std;

int GetNumber() {
    int Number = 0;
    cout << "Please enter your number ? \n";
    cin >> Number;
    return Number;
}

string CheckNumberType(int Number) {
    if (Number % 2 == 0) 
        return "Even";
    else 
        return "Odd";
}

void PrintNumberType(string result) {
    cout << " \n The number type is " << result << endl;
}

int main() {

    PrintNumberType(CheckNumberType(GetNumber()));
    return 0;
}