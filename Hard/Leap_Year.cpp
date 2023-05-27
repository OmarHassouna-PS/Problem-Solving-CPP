#include <iostream>
#include "InputLib.h"
#include "Mathlib.h"

using namespace std;

bool IsLeapYear (short Year) {

    if (Year % 400 == 0)
        return true;
    else if (Year % 4 == 0 && Year % 100 != 0) 
        return true; 
    return false;

    /* return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0); */
}

int main() {

    short Year = 2004;
    if (IsLeapYear(Year))
        cout << "Leap Year!";
    else 
        cout << "Not Leap Year!";

    return 0;
}