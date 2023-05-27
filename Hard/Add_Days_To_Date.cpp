#include <iostream>
#include <cstdio>
#include "InputLib.h"
#include "Mathlib.h"

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

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

stDate ConvertNumberDayToDate (stDate Date, short NumberDayToAdd) {

    for (size_t j = 0; j < NumberDayToAdd ; j++) {
        Date.Day++;
        if (Date.Month > 12) {
            Date.Year++;
            Date.Month = 1;
        }
        else if (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month)) {
            Date.Month++;
            Date.Day = 0;
        }
    }
    return Date;
}


int main() {

    stDate Date;
    Date.Year = 2022;
    Date.Month = 11;
    Date.Day = 10;

    short DaysAdded = 150;

    ConvertNumberDayToDate( Date, DaysAdded );

    return 0;
} 