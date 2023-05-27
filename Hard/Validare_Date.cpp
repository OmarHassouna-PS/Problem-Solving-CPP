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

short NumberOfDaysInMonth( stDate Date ) {

    int NumberOfDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Date.Month == 2) ? (IsLeapYear(Date.Year) ? 29 : 28) : NumberOfDays[Date.Month - 1];  
}

bool ValidateDate (stDate Date) {

    return (Date.Day <= NumberOfDaysInMonth(Date) && Date.Month <= 12 && Date.Month >= 1);
}

int main() {

    stDate Date;
    Date.Day = 28; 
    Date.Month = 1; 
    Date.Year = 2022;


    if (ValidateDate( Date ))
        cout << "\nYes, Date is a Valid date";
    else 
        cout << "\nNo, Date is a Not Valid date";
        
    return 0;
}