#include <iostream>

using namespace std;

string GetString (string Message = "" ) {
    
    string text = "\0";
    cout << Message << endl;
    getline(cin, text); 

    return text;
}

bool IsVowel(char chr) {

    return ((chr == 'a') || (chr == 'e') || (chr == 'i') || (chr == 'o') || (chr == 'u'));
}

void PrintVowelsLetter (string Name) {

    for (size_t i = 0; i < Name.length() ; i++)
    {
        if (IsVowel(Name[i]))
        {
            cout << Name[i] << "\t";
        }
    } 
    cout << endl;
}

int main() {

    string Name = GetString("Please Enter yore String?");

    cout << "Vowels in string are:\t";

    PrintVowelsLetter (Name);
    
    return 0;
}