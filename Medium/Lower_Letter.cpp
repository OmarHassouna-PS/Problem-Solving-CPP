#include <iostream>
#include <iomanip>

#include "InputLib.h"
#include "Mathlib.h"

using namespace std;

string LowerFirstLetterOfEachWord (string Name) {

    bool IsFirstLetter = true;
    cout << "\nFirst letter of this string: \n";
    for (size_t i = 0; i < Name.length() ; i++)
    {
        if (Name[i] != ' ' && IsFirstLetter)
        {
           Name[i] = tolower(Name[i]);
        }
        IsFirstLetter = (Name[i] == ' ' ? true : false);
    } 
    return Name;
}

int main() {

    string Name = Input::GetString("Please Enter yore String?");

    cout << LowerFirstLetterOfEachWord("Please Enter yore String") << endl;


    return 0;
}