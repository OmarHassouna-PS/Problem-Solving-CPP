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

stDate IncreaseDateByDays (stDate Date, short NumberDayToAdd) {

    for (size_t i = 0; i < NumberDayToAdd ; i++) {

        if (IsWeekEnd(DayOfWeekOrder(Date)))
            NumberDayToAdd++;

        if (Date.Day == NumberOfDaysInMonth(Date)) {
            Date.Month++;
            Date.Day = 1;
        
            if (Date.Month > 12) {
            Date.Year++;
            Date.Month = 1;
            }
        }
        else {
            Date.Day++;
        }
    }
    return Date;
}

int main() {

    stDate DateFrom;
    DateFrom.Day = 1;
    DateFrom.Month = 1;
    DateFrom.Year = 2022;

    short Vacation = 23;
    
    cout << "\nVacation Starts: " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year;

    stDate ReturnDate = IncreaseDateByDays(DateFrom, Vacation);

    cout << "\nVacation From: " << DayName(DayOfWeekOrder(ReturnDate)) << " , " << 
        ReturnDate.Day << "/" << ReturnDate.Month << "/" << ReturnDate.Year;

    return 0;
}