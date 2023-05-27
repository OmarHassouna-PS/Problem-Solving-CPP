#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum enCharType {SmallLetter = 1, CapitalLatter = 2, SpecialCharacter = 3, Digit = 4};

int RandomNumber(int From, int To) {

    return rand()% (To - From + 1) + From;
}

char GetRandomCharacter(enCharType CharType) {

    switch(CharType)
    {
        case enCharType::SmallLetter:
        {
            return char(RandomNumber(97, 122));
        }
        case enCharType::CapitalLatter:
        {
            return char(RandomNumber(65, 90));
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
        }
    }
    return 0;
}

int main() {
     
    srand((unsigned)time(0));
 
    cout << GetRandomCharacter(enCharType::SmallLetter) << endl;
    cout << GetRandomCharacter(enCharType::CapitalLatter) << endl;
    cout << GetRandomCharacter(enCharType::SpecialCharacter) << endl;
    cout << GetRandomCharacter(enCharType::Digit) << endl;
    return 0;
}