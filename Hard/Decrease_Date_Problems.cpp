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

short NumberOfDaysInMonth( short Year, short Month ) {

     int NumberOfDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];  
} 

stDate DecreaseDateByDays (stDate Date, short NumberDaysToDecrease) {

    for (size_t i = 0; i < NumberDaysToDecrease; i++)
    {
        if (Date.Day == 1) {
        
            if (Date.Month == 1) {
                Date.Day = 31;
                Date.Month = 12;
                Date.Year--;
            }
            else {
                Date.Month--;
                Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
            }
        }
        else {
            Date.Day--;
        }
    }
    return Date;
}

stDate DecreaseDateByWeeks (stDate Date, short NumberWeeksToDecrease) {

    Date = DecreaseDateByDays(Date, (NumberWeeksToDecrease * 7));
    return Date;
}

stDate DecreaseDateByMonth (stDate Date, short NumberMonthToDecrease) {

    for (size_t j = 0; j < NumberMonthToDecrease ; j++) {

        if (Date.Month == 1) {
            Date.Year--;
            Date.Month = 12;
        }
        else {
            Date.Month--;
        }
        
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > NumberOfDaysInCurrentMonth)
        Date.Day = NumberOfDaysInCurrentMonth;
    
    return Date;
}

stDate DecreaseDateByYear (stDate Date, short NumberYearToDecrease) {

    Date.Year -= NumberYearToDecrease;
    return Date;
}

stDate DecreaseDateByDecade (stDate Date, short NumberYearToDecrease) {

    Date.Year -= (NumberYearToDecrease * 10);
    return Date;
}

stDate DecreaseDateByCentury (stDate Date, short NumberYearToDecrease) {

    Date.Year -= (NumberYearToDecrease * 100);
    return Date;
}

stDate DecreaseDateByMillennium (stDate Date, short NumberYearToDecrease) {

    Date.Year -= (NumberYearToDecrease * 1000);
    return Date;
}

int main() {
    stDate Date1;
    
    Date1.Year = 2023;
    Date1.Month = 1;
    Date1.Day = 1;

    cout << "Date After: \n\n";

    Date1 = DecreaseDateByDays( Date1, 1 );
    cout << "01-Decreaseing one Day is: "        <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByDays( Date1, 10 );
    cout << "01-Decreaseing 10 Days is: "        <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByWeeks( Date1, 1 );
    cout << "01-Decreaseing one week is: "       <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByWeeks( Date1, 10 );
    cout << "01-Decreaseing 10 weeks is: "       <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByMonth( Date1, 1 );
    cout << "01-Decreaseing one month is: "      <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByMonth( Date1, 5 );
    cout << "01-Decreaseing 5 months is: "      <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByYear( Date1, 1 );
    cout << "01-Decreaseing one Year is: "       <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByYear( Date1, 10 );
    cout << "01-Decreaseing 10 Years is: "       <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByDecade( Date1, 1 );
    cout << "01-Decreaseing one Decade is: "     <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByCentury( Date1, 1 );
    cout << "01-Decreaseing one Century is: "    <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = DecreaseDateByMillennium( Date1, 1 );
    cout << "01-Decreaseing One Millennium is: " <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    return 0;
} 