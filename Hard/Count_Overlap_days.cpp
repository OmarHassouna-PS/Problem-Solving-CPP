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

short DifferenceBetweenTwoDates (stDate Date1, stDate Date2, bool includeEndDay = false) {

    short Count = 0;
    while (true) {   
        Count++;
        Date1.Day++;
        if (Date1.Month > 12) {
            Date1.Year++;
            Date1.Month = 1;
        }
        else if (Date1.Day == NumberOfDaysInMonth(Date1)) {
            Date1.Month++;
            Date1.Day = 0;
        }
        if (IsDate1EqualDate2(Date1, Date2)) {
            break;
        }
    }
    return includeEndDay ? ++Count : Count;
}

stDate IncreaseDateByOneDay(stDate Date) { 
    if (Date.Day == NumberOfDaysInMonth(Date)) { 
        if (Date.Month == 12) { 
            Date.Month = 1; 
            Date.Day = 1; 
            Date.Year++;         
        } 
        else { 
            Date.Day = 1; 
            Date.Month++;         
        }     } 
    else { 
        Date.Day++;     
    } 
    return Date; 
}

int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false) { 
    return DifferenceBetweenTwoDates(Period.StartDate, Period.EndDate, IncludeEndDate);
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) { 
    if (         
        CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before        
        ||         
        CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After        
        ) 
        return false; 
    else 
        return true; 
} 

bool isDateInPeriod(stDate Date, stPeriod Period) { 
    return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before || CompareDates(Date, Period.EndDate) == enDateCompare::After); 
}

int CountOverlapDays(stPeriod Period1, stPeriod Period2) { 

    int Period1Length = PeriodLengthInDays(Period1, true); 
    int Period2Length = PeriodLengthInDays(Period2, true); 
    int OverlapDays = 0; 

    if (!IsOverlapPeriods(Period1, Period2)) 
        return 0; 
    if (Period1Length < Period2Length)     { 
        while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate)) 
        { 
            if (isDateInPeriod(Period1.StartDate, Period2))                 
                OverlapDays++;
                 
            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);         
        }     
    } 
    else    
    { 
        while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))         
        { 
            if (isDateInPeriod(Period2.StartDate, Period1))                 
                OverlapDays++; 
            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);         
        }     
    } 
    return OverlapDays; 
} 

int main() {

    stPeriod Period1;
    Period1.StartDate.Day = 1; 
    Period1.StartDate.Month = 1; 
    Period1.StartDate.Year = 2022;

    Period1.EndDate.Day = 10; 
    Period1.EndDate.Month = 1; 
    Period1.EndDate.Year = 2052;

    stPeriod Period2;

    Period2.StartDate.Day = 5; 
    Period2.StartDate.Month = 1; 
    Period2.StartDate.Year = 2022;

    Period2.EndDate.Day = 9; 
    Period2.EndDate.Month = 1; 
    Period2.EndDate.Year = 2022;


    cout << "\nPeriod Length is : " << CountOverlapDays(Period1, Period2);;

    return 0;
}