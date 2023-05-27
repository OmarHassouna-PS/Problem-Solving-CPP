#include <iostream>
#include "InputLib.h"
#include "Mathlib.h"

using namespace std;

bool IsLeapYear ( short Year ) {
    
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0); 
}

short NumberOfDaysInAYear(short Year) {
    return  IsLeapYear(Year) ? 366 : 365; 
} 

short NumberOfHoursInAYear(short Year) {
    return  NumberOfDaysInAYear(Year) * 24; 
}

int NumberOfMinutesInAYear(short Year) {
    return  NumberOfHoursInAYear(Year) * 60; 
} 

int NumberOfSecondsInAYear(short Year) {
    return  NumberOfMinutesInAYear(Year) * 60; 
} 

int main() {

    short Year = 2004;

    cout << "\nNumber of Days in year    [" << Year << "] is " << NumberOfDaysInAYear(Year);
    cout << "\nNumber of Hours in year   [" << Year << "] is " << NumberOfHoursInAYear(Year);
    cout << "\nNumber of Minutes in year [" << Year << "] is " << NumberOfMinutesInAYear(Year);
    cout << "\nNumber of Seconds in year [" << Year << "] is " << NumberOfSecondsInAYear(Year);

    return 0;
}