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

void  SwapDates(stDate& Date1, stDate& Date2) { 

    stDate TempDate;   

    TempDate.Year = Date1.Year;     
    TempDate.Month = Date1.Month;     
    TempDate.Day = Date1.Day; 

    Date1.Year = Date2.Year; 
    Date1.Month = Date2.Month; 
    Date1.Day = Date2.Day; 

    Date2.Year = TempDate.Year; 
    Date2.Month = TempDate.Month; 
    Date2.Day = TempDate.Day; 
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false); 
}

short DifferenceBetweenTwoDates (stDate Date1, stDate Date2, bool includeEndDay = false) {

    short Days = 0;
    short SwapFlagValue = 1; 

    if (!IsDate1BeforeDate2(Date1, Date2)) {
        //Swap Dates         
        SwapDates(Date1, Date2);         
        SwapFlagValue = -1;     
    }

    while (true) {   
        Days++;
        Date1.Day++;
        if (Date1.Month > 12) {
            Date1.Year++;
            Date1.Month = 1;
        }
        else if (Date1.Day == NumberOfDaysInMonth(Date1.Year, Date1.Month)) {
            Date1.Month++;
            Date1.Day = 0;
        }
        if (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day){
            break;
        }
    }
    return includeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}


int main() {
    stDate Date1;
    stDate Date2;
    
    Date1.Year = 1950;
    Date1.Month = 1;
    Date1.Day = 1;

    Date2.Year = 2022;
    Date2.Month = 1;
    Date2.Day = 1;

    cout << "Difference is: "<<DifferenceBetweenTwoDates( Date1, Date2, true  ) << " Day(s)\n";

    return 0;
} 