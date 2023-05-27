#include <iostream>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

struct stPeriod 
{
    stDate StartDate;
    stDate EndDate;
};

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

bool IsLeapYear ( short Year ) {

    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0); 
}

short NumberOfDaysInMonth( stDate Date ) {

    int NumberOfDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Date.Month == 2) ? (IsLeapYear(Date.Year) ? 29 : 28) : NumberOfDays[Date.Month - 1];  
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false); 
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2) { 
    return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false; 
}

enDateCompare CompareDates(stDate Date1, stDate Date2) {

    if (IsDate1BeforeDate2(Date1, Date2)) 
        return enDateCompare::Before; 
    if (IsDate1EqualDate2(Date1, Date2)) 
        return enDateCompare::Equal; 
    /* if (IsDate1AfterDate2(Date1,Date2))         
    return enDateCompare::After;*/ 
    //this is faster
    return enDateCompare::After; 
}

bool IsOverlapPeriods (stPeriod Period1, stPeriod Period2) {

/*     if (IsDate1EqualDate2(Period1.StartDate, Period2.StartDate))
        return true;
    else if (IsDate1EqualDate2(Period1.EndDate, Period2.EndDate))
        return true;
    else if (IsDate1EqualDate2(Period1.EndDate, Period2.StartDate))
        return true;
    else if (IsDate1EqualDate2(Period1.StartDate, Period2.EndDate))
        return true;
    else if (!IsDate1BeforeDate2(Period1.EndDate, Period2.StartDate))
        return true;
    else if (!IsDate1BeforeDate2(Period1.StartDate, Period2.EndDate))
        return true;
    else
        return false; */
     if (
    CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before 
    ||
    CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After
        )
        return false;
    else
        return true; 
}

int main() {

    stPeriod Period1;
    Period1.StartDate.Day = 1; 
    Period1.StartDate.Month = 1; 
    Period1.StartDate.Year = 2022;

    Period1.EndDate.Day = 10; 
    Period1.EndDate.Month = 1; 
    Period1.EndDate.Year = 2022;

    stPeriod Period2;

    Period2.StartDate.Day = 11;
    Period2.StartDate.Month = 1; 
    Period2.StartDate.Year = 2022;

    Period2.EndDate.Day = 12; 
    Period2.EndDate.Month = 1; 
    Period2.EndDate.Year = 2022;
    
    if (IsOverlapPeriods(Period1, Period2))
        cout << "\nYes, Periods Overlap!";
    else
        cout << "\nNo, Dont Periods Overlap!";

    return 0;
}