#include <iostream>
using namespace std;

short ReadNumber() {

    short N = 0;
    cout << "Please enter number  \n";
    cin >> N;
    return N;
}

short Factorial(short N) {

    if (N == 1)
        return 1;

    return N * Factorial(N - 1);

}

void PrintRuslt (short Fact) {

    cout << Fact << endl;
}
int main() {

    PrintRuslt(Factorial(ReadNumber()));
    return 0;
}