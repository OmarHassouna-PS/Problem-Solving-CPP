#include <iostream>
#include <vector>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

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

string ReadStringDate () {

    string Date = "\0";
    cout << "Please enter Date dd/mm/yyyy?\n";
    getline(cin, Date);
    return Date;
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

string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo) { 

    short pos = S1.find(StringToReplace); 
    while (pos != std::string::npos) { 
        S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);         
        pos = S1.find(StringToReplace);
        //find next    
    } return S1; 
}

string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy") { 

    string FormattedDateString = "";     
    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));     
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));     
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year)); 
    return  FormattedDateString; 
} 

int main() {

    string StrDate = ReadStringDate();
    stDate Date = StringToDate(StrDate);

    cout << "\nDay: " << Date.Day << "\nMonth: " << Date.Month << "\nYear: " << Date.Year;
    cout << "\n\nYouEntered: " << DateToString(Date);
    cout << "\n\nYouEntered: " << FormateDate(Date, "dd-mm-yyyy");
    return 0;
}