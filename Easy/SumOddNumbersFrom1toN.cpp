#include <iostream>
using namespace std;

short ReadNumber() {

    short N = 0;
    cout << "Please enter number  \n";
    cin >> N;
    return N;
}

short countRangFrom1toN (short N) {

    short sum = 0;
    for (size_t i = 0; i <= N; i++)
    {
        if (i % 2 == 0)
            continue;
        sum += i;
    }
    return sum;
}

void PrintRuslt (short sum) {

    cout << sum << endl;
}
int main() {

    PrintRuslt(countRangFrom1toN(ReadNumber()));
    return 0;
}