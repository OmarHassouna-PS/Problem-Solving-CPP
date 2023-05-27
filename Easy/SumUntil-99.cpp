#include <iostream>
using namespace std;


int ReadNumber() {
    int Num = 0;
    int Sum = 0;
    while (Num != -99)
    {
        cout << "Please enter number\n";
        cin >> Num;
        Sum += Num;
    }
    return Sum;
}

void PrintResult(int Sum) {

    cout << " \n The result is " << Sum << endl;
}

int main() {


    PrintResult(ReadNumber());
    return 0;
}