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

stDate IncreaseDateByDays (stDate Date, short NumberDayToAdd) {

    for (size_t i = 0; i < NumberDayToAdd ; i++) {

        if (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month)) {
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

stDate IncreaseDateByWeeks (stDate Date, short NumberWeeksToAdd) {

    for (size_t j = 0; j < (NumberWeeksToAdd * 7) ; j++) {

        if (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month)) {
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

stDate IncreaseDateByMonth (stDate Date, short NumberMonthToAdd) {

    for (size_t j = 0; j < NumberMonthToAdd ; j++) {

        if (Date.Month > 12) {
            Date.Year++;
            Date.Month = 1;
        }
        Date.Month++;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
    if (Date.Day != NumberOfDaysInCurrentMonth)
        Date.Day = NumberOfDaysInCurrentMonth;
    
    return Date;
}

stDate IncreaseDateByYear (stDate Date, short NumberYearToAdd) {

    Date.Year += NumberYearToAdd;
    return Date;
}

stDate IncreaseDateByDecade (stDate Date, short NumberYearToAdd) {

    Date.Year += (NumberYearToAdd * 10);
    return Date;
}

stDate IncreaseDateByCentury (stDate Date, short NumberYearToAdd) {

    Date.Year += (NumberYearToAdd * 100);
    return Date;
}

stDate IncreaseDateByMillennium (stDate Date, short NumberYearToAdd) {

    Date.Year += (NumberYearToAdd * 1000);
    return Date;
}

int main() {
    stDate Date1;
    
    Date1.Year = 2022;
    Date1.Month = 12;
    Date1.Day = 25;

    cout << "Date After: \n\n";

    Date1 = IncreaseDateByDays( Date1, 1 );
    cout << "01-Adding one Day is: "        <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByDays( Date1, 10 );
    cout << "01-Adding 10 Days is: "        <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByWeeks( Date1, 1 );
    cout << "01-Adding one week is: "       <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByWeeks( Date1, 10 );
    cout << "01-Adding 10 weeks is: "       <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByMonth( Date1, 1 );
    cout << "01-Adding one month is: "      <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByMonth( Date1, 10 );
    cout << "01-Adding 10 months is: "      <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByYear( Date1, 1 );
    cout << "01-Adding one Year is: "       <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByYear( Date1, 10 );
    cout << "01-Adding 10 Years is: "       <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByDecade( Date1, 1 );
    cout << "01-Adding one Decade is: "     <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByCentury( Date1, 1 );
    cout << "01-Adding one Century is: "    <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByMillennium( Date1, 1 );
    cout << "01-Adding One Millennium is: " <<  Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    return 0;
} 