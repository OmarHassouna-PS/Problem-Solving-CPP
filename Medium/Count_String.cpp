#include <iostream>

using namespace std;

string GetString (string Message = "" ) {
    
    string text = "\0";
    cout << Message << endl;
    getline(cin, text); 

    return text;
}

bool IsUpperOrLower (char chr) {

    return isupper(chr) ? true : false;
}

void CountLetters (string Name, short& CountStr, short& CountSmallLetter, short& CountCapitalLetter) {

    for (size_t i = 0; i < Name.length() ; i++)
    {
        if (isalpha(Name[i]))
        {
            CountStr++;
            if (IsUpperOrLower(Name[i])) 
                CountCapitalLetter++;
            else
                CountSmallLetter++;
        }
    } 
}

int main() {

    short CountStr = 0, CountSmallLetter = 0, CountCapitalLetter = 0; 

    string Name = GetString("Please Enter yore String?");

    CountLetters (Name, CountStr, CountSmallLetter, CountCapitalLetter);
    cout << "String  Length = " << CountStr << endl;
    cout << "Small   Letter = " << CountSmallLetter << endl;
    cout << "Capital Length = " << CountCapitalLetter << endl;

    return 0;
}