#include <iostream>
using namespace std;

void Fibonacci_Series (short Number) {
    
    short Prev1 = 1, Prev2 = 1, timb = 0;
    cout << Prev1 << " " << Prev1 << " ";
    for (size_t i = 0; i < Number - 2; i++)
    {
        timb = Prev1;
        Prev1 = Prev1 + Prev2;
        Prev2 = timb;
        cout << Prev1 << " ";
    }
}


int main() {

    Fibonacci_Series(10);
    return 0;
}