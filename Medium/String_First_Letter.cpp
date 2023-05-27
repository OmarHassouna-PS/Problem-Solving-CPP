#include <iostream>
#include <iomanip>

#include "InputLib.h"
#include "Mathlib.h"

using namespace std;

void PrintFirstLetterOfEachWord (string Name) {

/*     cout << Name[0] << endl;
    for (size_t i = 0; i < Name.length() ; i++)
    {
        if (Name[i] == ' ')
        {
            cout << Name[i + 1] << endl;
        }
    }
     */
     bool IsFirstLetter = true;
    cout << "\nFirst letter of this string: \n";
    for (size_t i = 0; i < Name.length() ; i++)
    {
        if (Name[i] != ' ' && IsFirstLetter)
        {
            cout << Name[i] << endl;
        }
        IsFirstLetter = (Name[i] == ' ' ? true : false);
    } 

}
int main() {

    string Name = Input::GetString("Please Enter yore String?");
    PrintFirstLetterOfEachWord(Name);


    return 0;
}