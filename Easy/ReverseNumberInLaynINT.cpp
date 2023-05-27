#include <iostream>
#include <string>
#include <cstring>
#include <limits.h>

using namespace std;

int ReversNumber (int Number) {

    int Remainder = 0;
    int Number2 = 0;

    while (Number != 0)
    {
        Remainder = Number % 10;
        Number /= 10;

        if (Number2 > INT_MAX/10 || (Number2 == INT_MAX/10 && Remainder >= INT_MAX%10)) 
            return 0;
        if (Number2 < INT_MIN/10 || (Number2 == INT_MIN/10 && Remainder <= INT_MIN%10)) 
            return 0; 

        Number2 = (Number2 * 10) + Remainder;
    }

    return Number2;
}

int main() {

    cout << ReversNumber(-54196);
    return 0;
}