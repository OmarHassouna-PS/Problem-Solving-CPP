#pragma once

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
    short Hour;
    short Minutes;
    int Second;
    short WeekDay;
    short YearDay;
    int HoursOfDayLightSavings;
};

namespace DateLid { 

    vector <string> Split (string str, string delim) {

        vector <string> vWord;

        short pos = 0;
        string sWord = "\0";

        
        while ((pos = str.find(delim)) != std::string::npos) {

            sWord = str.substr(0, pos);
            if (sWord != "") {
                vWord.push_back(sWord);
            }
            str.erase(0, pos + delim.length()); 
        }

        if (str != "") {
            vWord.push_back(str);
        }
        return vWord;
    }

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

    stDate GetSystemDate () {

        time_t t = time(0);   // get time now
        tm* now = localtime(&t);

        stDate DateNow;

        DateNow.Year = now->tm_year + 1900;
        DateNow.Month = now->tm_mon + 1;
        DateNow.Day = now->tm_mday;
        DateNow.Hour = now->tm_hour;
        DateNow.Minutes = now->tm_min;
        DateNow.Second = now->tm_sec;
        DateNow.WeekDay = now->tm_wday;
        DateNow.YearDay = now->tm_yday;
        DateNow.HoursOfDayLightSavings= now->tm_isdst;

        return DateNow;
    }

    bool IsLastDayInMonth (short Year, short Month, short Day) {

        return (Day == NumberOfDaysInMonth(Year, Month));
    }

    bool IsLastMonthInYear (short Month) {

        return (Month == 12);
    }

    bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
        return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false); 
    }

    bool IsDate1EqualDate2(stDate Date1, stDate Date2) { 
        return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false; 
    }

    bool ValidateDate (stDate Date) {

    return (Date.Day == NumberOfDaysInMonth(Date) && Date.Month <= 12 && Date.Month >= 1);
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

    short DifferenceBetweenTwoDates (stDate Date1, stDate Date2, bool includeEndDay = false) {

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
            if (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day){
                break;
            }
        }
        return includeEndDay ? ++Count : Count;
    }

    short NumberOfDaysFromTheBeginingOfTheYear ( stDate Date ) {

        short SumDay = 0;

        for (size_t j = 1; j <= Date.Month - 1; j++) {

            SumDay += NumberOfDaysInMonth(Date.Year, j);
        }
        return SumDay + Date.Day;
    }

    stDate ConvertNumberDayToDateWithoutMonth (short DaysOrderInYear, short Year /*input Day and Year*/) {
        stDate Date;
        short Month = 1, CounterDay = 0, TotalDayOfMonth = 0;

        for (size_t j = 1; j < DaysOrderInYear ; j++) {
            CounterDay++;
            if (CounterDay == NumberOfDaysInMonth(Year, Month)) {
                Month++;
                TotalDayOfMonth += CounterDay;
                CounterDay = 0;
            }
        }
        Date.Day = DaysOrderInYear - TotalDayOfMonth; 
        Date.Month =  Month;
        Date.Year = Year;
        return Date;
    }

    string DayName ( short Day ) {
    
        string Name[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
        return Name[Day - 1];
    }

    string MonthName ( short Month ) {
    
        string Name[] = { "January", "February", "Mach", "April", "May", "June", "July",
        "August", "September", "October", "November", "December" };
        return Name[Month - 1];
    }

    stDate StringToDate (string StrDate) {

    vector <string> SpDate = Split(StrDate, "/");
    stDate Date;

    Date.Day = stoi(SpDate[0]); 
    Date.Month = stoi(SpDate[1]); 
    Date.Year =stoi(SpDate[2]); 

    return Date;
    }

    string DateToString (stDate Date) {

    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

    short DayOfWeekOrder ( short Year, short Month, short Day ) {

        short a = (14 - Month) / 12;
        short y = Year - a;
        short m = Month + (12 * a) - 2;
        // Gregorian
        // 0:Sun, 1:Mon, 2:Tue...etc
        return ((Day + y) + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }
    
    short NumberOfHoursInMonth(short Year, short Month) {
        return  NumberOfDaysInMonth(Year, Month) * 24; 
    }

    int NumberOfMinutesInMonth(short Year, short Month) {
        return  NumberOfHoursInMonth(Year, Month) * 60; 
    } 

    int NumberOfSecondsInMonth(short Year, short Month) {
        return  NumberOfMinutesInMonth(Year, Month) * 60; 
    } 

    short NumberOfDaysInAYear(short Year) {
        return  IsLeapYear(Year) ? 366 : 365; 
    } 

    short NumberOfHoursInAYear(short Year) {
        return  NumberOfDaysInAYear(Year) * 24; 
    }

    int NumberOfMinutesInAYear(short Year) {
        return  NumberOfHoursInAYear(Year) * 60; 
    } 

    int NumberOfSecondsInAYear(short Year) {
        return  NumberOfMinutesInAYear(Year) * 60; 
    } 

    string NumberToText(int Number) { 

        if (Number == 0) {
            return"";     
        } 
        if (Number >= 1 && Number <= 19) {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" }; 
           return  arr[Number] + " ";     
        } 
        if (Number >= 20 && Number <= 99) { 
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);     
        } 
        if (Number >= 100 && Number <= 199) {
            return"One Hundred " + NumberToText(Number % 100);     
        } 
        if (Number >= 200 && Number <= 999) { 
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        } 
        if (Number >= 1000 && Number <= 1999) {
            return"One Thousand " + NumberToText(Number % 1000);    
        } 
        if (Number >= 2000 && Number <= 999999) { 
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000); 
        } 
        if (Number >= 1000000 && Number <= 1999999) {
            return"One Million " + NumberToText(Number % 1000000);     
        } 
        if (Number >= 2000000 && Number <= 999999999) { 
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        } 
        if (Number >= 1000000000 && Number <= 1999999999) {
            return"One Billion " + NumberToText(Number % 1000000000);
        } 
        else { 
            return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }
    }

    void PrintMonthCalender ( short Month, short Year) {

        short NumberOfDays = 0;
        // Index of the day from 0 to 6
        short current = DayOfWeekOrder(Year, Month, 1);
        
        NumberOfDays = NumberOfDaysInMonth(Year, Month);
        
        // Print the current month name
        printf("\n  _______________%s_______________\n\n", MonthName(Month).c_str());

        // Print the columns
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        int i;
        for (i = 0; i < current; i++)
            printf("     ");

        for (size_t j = 1; j <= NumberOfDays; j++) {
            printf("%5d", j);

            if (++i == 7) {
                i = 0;
                printf("\n");
            }
        }
        printf("\n  _____________________________________\n");
    }
}