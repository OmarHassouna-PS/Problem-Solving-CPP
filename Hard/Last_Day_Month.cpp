#include <iostream>
#include <cstdio>
#include "InputLib.h"
#include "Mathlib.h"

using namespace std;

bool IsLeapYear ( short Year ) {
    
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0); 
}

short NumberOfDaysInMonth( short Year, short Month ) {

     int NumberOfDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];  
} 

bool IsLastDayInMonth (short Year, short Month, short Day) {

    return (Day == NumberOfDaysInMonth(Year, Month));
}

bool IsLastMonthInYear (short Month) {

    return (Month == 12);
}

int main() {

    short Year = 2000;
    short Month = 2;
    short Day = 29;

    if (IsLastDayInMonth( Year, Month, Day )) {
        cout << "\nYes, Day is Last Day in Month.\n";
    }
    else {
        cout << "No, Day is Not Last Day in Month.\n";
    }
    if (IsLastMonthInYear( Month )) {
        cout << "Yes, Month is Last Month in Year.\n";
    }
    else {
        cout << "No, Month is Not Last Month in Year.\n";
    }

    return 0;
} 