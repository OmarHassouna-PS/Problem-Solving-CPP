#include <iostream>
#include "DateLib.h"

using namespace std;

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

bool IsEndOfWeek (short DateNumberOfDay) {

    return (DateNumberOfDay == 6);
}

bool IsWeekEnd (short DateNumberOfDay) {

    return (DateNumberOfDay == 6 || DateNumberOfDay == 5);
}

bool IsBusinessDay (short DateNumberOfDay) {

    return !IsWeekEnd(DateNumberOfDay);
}

short DaysUntilTheEndOfweek (short DateNumberOfDay) {

    return 6 - DateNumberOfDay;
}

short DaysUntilTheEndOfMonth (stDate Date) {

    return NumberOfDaysInMonth(Date) - Date.Day;
}

short DaysUntilTheEndOfYear (stDate Date) {

    short SumDay = 0;

    for (Date.Month; Date.Month <= 12; Date.Month++) {

        SumDay += NumberOfDaysInMonth(Date);
    }
    return SumDay - Date.Day;
}

int main() {


    stDate Date = DateLid::GetSystemDate();
    short DayNumberOfWeek = DayOfWeekOrder(Date);
    cout << "Today is " << DayName(DayNumberOfWeek) << "  ," << Date.Year << "/" << Date.Month << "/" << Date.Day << endl;

    cout << "\nIS it End of week?\n";
    if (IsEndOfWeek(DayNumberOfWeek))
        cout << "Yes is the end of the week.\n";
    else
        cout << "No Not end of the week.\n";
    
    cout << "\nIS it weekend?\n";
    if (IsWeekEnd(DayNumberOfWeek))
        cout << "Yes it is a week end.\n";
    else
        cout << "No, it is a  Not weekend.\n";
    
    cout << "\nIS it weekend?\n";
    if (IsBusinessDay(DayNumberOfWeek))
        cout << "Yes it is a business day.\n";
    else
        cout << "No, it is Not a business day.\n";
    
    cout << "\nDays Until end of Week : " << DaysUntilTheEndOfweek(DayNumberOfWeek) << " Day(s).";
    cout << "\nDays Until end of Month : " << DaysUntilTheEndOfMonth(Date) << " Day(s).";
    cout << "\nDays Until end of Year : " << DaysUntilTheEndOfYear(Date) << " Day(s).";
    return 0;
}