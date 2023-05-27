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

short DayOfWeekOrder ( short Year, short Month, short Day ) {

    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    // Gregorian
    // 0:Sun, 1:Mon, 2:Tue...etc
    return ((Day + y) + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string MonthName ( short Month ) {
    
    string Name[] = { "January", "February", "Mach", "April", "May", "June", "July",
    "August", "September", "October", "November", "December" };
    return Name[Month - 1];
}

void PrintMonthCalender ( short Month, short Year) {

    // Index of the day from 0 to 6
    short current = DayOfWeekOrder(Year, Month, 1 );
    short NumberOfDays = 0;
    NumberOfDays = NumberOfDaysInMonth(Year, Month);
    
    // Print the current month name
    printf("\n  _______________%s_______________\n\n", MonthName(Month).c_str());

    // Print the columns
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for (i = 0; i < current; i++)
        printf("     ");

    for (size_t j = 1; j <= NumberOfDays; j++) {
        printf("%5d", j);

        if (++i == 7) {
            i = 0;
            printf("\n");
        }
    }
    printf("\n  _____________________________________\n");
}

int main() {

    short Year = 2022;
    short Month = 2;

    PrintMonthCalender(Month, Year);

    return 0;
} 