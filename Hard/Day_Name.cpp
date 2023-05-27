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

string DayName ( short Day ) {
    
    string Name[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return Name[Day];
}

int main() {

    short Year = 2022;
    short Month = 10;
    short Day = 22;

    short DayResult = DayOfWeekOrder(Year, Month, Day);

    cout << "\nDate      : " << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order : " << DayResult;
    cout << "\nDay Name  : " << DayName (DayResult);

    return 0;
} 