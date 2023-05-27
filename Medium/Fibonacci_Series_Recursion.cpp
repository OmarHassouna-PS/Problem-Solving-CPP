#include <iostream>
using namespace std;

void Fibonacci_Series (short Number, short Prev1, short Prev2, short temp) {
    
    if (Number - 2 == 0) {
        return;
    }

    temp = Prev1;
    Prev1 = Prev1 + Prev2;
    Prev2 = temp; 

    cout << Prev1 << " ";
    Fibonacci_Series (Number - 1, Prev1, temp, Prev1);
    
}

int main() {

    cout << "1 1 ";
    Fibonacci_Series(10, 1, 1, 0);
    return 0;
}