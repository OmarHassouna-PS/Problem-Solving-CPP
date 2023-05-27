#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>

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

short GetDifferenceInDays (stDate Date1, stDate DateNow, bool includeEndDay = false) {

    short Count = 0;
    while (true) {   
        Count++;
        Date1.Day++;
        if (Date1.Month > 12) {
            Date1.Year++;
            Date1.Month = 1;
        }
        else if (Date1.Day == NumberOfDaysInMonth(Date1.Year, Date1.Month)) {
            Date1.Month++;
            Date1.Day = 0;
        }
        if (Date1.Year == DateNow.Year && Date1.Month == DateNow.Month && Date1.Day == DateNow.Day){
            break;
        }
    }
    return includeEndDay ? ++Count : Count;
}

stDate GetSystemDate () {

    time_t t = time(0);   // get time now
    tm* now = localtime(&t);

    stDate DateNow;

    DateNow.Year = now->tm_year + 1900;
    DateNow.Month = now->tm_mon + 1;
    DateNow.Day = now->tm_mday;

    return DateNow;
}

int main() {


    stDate Date1;
    
    Date1.Year = 1999;
    Date1.Month = 1;
    Date1.Day = 18;

     cout << "Difference is: "<< GetDifferenceInDays( Date1, GetSystemDate(), true  ) << " Day(s)\n";

    return 0;
} 