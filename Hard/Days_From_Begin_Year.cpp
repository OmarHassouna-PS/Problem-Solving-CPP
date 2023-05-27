#include <iostream>

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

short NumberOfDaysFromTheBeginingOfTheYear ( short Year, short Month, short Day) {

    short SumDay = 0;

    for (size_t j = 1; j <= Month - 1; j++) {

        SumDay += NumberOfDaysInMonth(Year, j);
    }
    return SumDay + Day;
}

void ConvertNumberDay (short DaysOrderInYear, short Year) {

    short Month = 1, M = 0, TotalDayOfMonth = 0;

    for (size_t j = 1; j < DaysOrderInYear ; j++) {
        M++;
        if (M == NumberOfDaysInMonth(Year, Month)) {
            Month++;
            TotalDayOfMonth += M;
            M = 0;
        }
    }
    cout << "\nData for [" << DaysOrderInYear << "] is: " << DaysOrderInYear - TotalDayOfMonth << "/" << Month << "/" << Year;
}

struct sDate { 
    short Year;
    short Month;
    short Day; 
}; 

sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {
    sDate Date;
    short RemainingDays = DateOrderInYear; 
    short MonthDays = 0;     
    Date.Year = Year;     
    Date.Month = 1; 
    while (true)     {
        MonthDays = NumberOfDaysInMonth(Date.Month, Year); 
        if (RemainingDays > MonthDays)         {   
            RemainingDays -= MonthDays;             
            Date.Month++;         
            } 
        else        {   
            Date.Day = RemainingDays; break;
                     }     
        } 
        return Date; 
}

int main() {

    short Year = 2022;
    short Month = 8;
    short Day = 31;

    short DaysOrderInYear = NumberOfDaysFromTheBeginingOfTheYear ( Year, Month, Day );
    cout << "\nNumber of Days from the begining of the year is " << DaysOrderInYear;
    ConvertNumberDay(DaysOrderInYear, Year);

    return 0;
} 