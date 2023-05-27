#include <iostream>

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

short DayOfWeekOrder ( stDate Date ) {

    short a = (14 - Date.Month) / 12;
    short y = Date.Year - a;
    short m = Date.Month + (12 * a) - 2;
    // Gregorian
    // 0:Sun, 1:Mon, 2:Tue...etc
    return ((Date.Day + y) + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short NumberOfDaysInMonth( stDate Date ) {

    int NumberOfDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Date.Month == 2) ? (IsLeapYear(Date.Year) ? 29 : 28) : NumberOfDays[Date.Month - 1];  
}

string DayName ( short Day ) {

    string Name[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return Name[Day];
}

bool IsWeekEnd (short DateNumberOfDay) {

    return (DateNumberOfDay == 6 || DateNumberOfDay == 5);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false); 
}

short DifferenceBetweenTwoDates (stDate Date1, stDate Date2, bool includeEndDay = false) {

    if (!IsDate1BeforeDate2(Date1, Date2))
        return 0;

    short Count = 0;
    while (true) {

        if (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day){
            break;
        }
        if (!IsWeekEnd(DayOfWeekOrder(Date1)))
            Count++;
        if (Date1.Month > 12) {
            Date1.Year++;
            Date1.Month = 1;
        }
        if (Date1.Day == NumberOfDaysInMonth(Date1)) {
            Date1.Month++;
            Date1.Day = 1;
        }
        Date1.Day++;
    }
    return includeEndDay ? ++Count : Count;
}

int main() {


    stDate DateFrom;
    DateFrom.Day = 1;
    DateFrom.Month = 1;
    DateFrom.Year = 2022;

    stDate DateTo;

    DateTo.Day = 30;
    DateTo.Month = 1;
    DateTo.Year = 2022;
    
    cout << "\nVacation From: " << DayName(DayOfWeekOrder(DateFrom)) << " , " << 
        DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year;

    cout << "\nVacation To: : " << DayName(DayOfWeekOrder(DateTo)) << " , " << 
        DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year;

    cout << "\n Actual Vacation Days is  : " << DifferenceBetweenTwoDates(DateFrom, DateTo) << " Day(s).";

    return 0;
}