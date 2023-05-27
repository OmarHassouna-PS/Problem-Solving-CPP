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

short NumberOfDaysInMonth(short Year, short Month ) {

    int NumberOfDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];  
} 

short NumberOfHoursInMonth(short Year, short Month) {
    return  NumberOfDaysInMonth(Year, Month) * 24; 
}

int NumberOfMinutesInMonth(short Year, short Month) {
    return  NumberOfHoursInMonth(Year, Month) * 60; 
} 

int NumberOfSecondsInMonth(short Year, short Month) {
    return  NumberOfMinutesInMonth(Year, Month) * 60; 
} 

int main() {

    short Year = 2000;
    short Month = 4;

    cout << "\nNumber of Days in Month    [" << Month << "] is " << NumberOfDaysInMonth(Year, Month);
    cout << "\nNumber of Hours in Month   [" << Month << "] is " << NumberOfHoursInMonth(Year, Month);
    cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Year, Month);
    cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Year, Month);

    return 0;
} 