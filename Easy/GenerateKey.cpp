#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
enum enCharType {SmallLetter = 1, CapitalLatter = 2, SpecialCharacter = 3, Digit = 4};

int ReadPositiveNumber (string Message) {

    int Number = 0;
    do {

        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

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

string CreatWord () {

    string Key ="";
    for (size_t i = 0; i < 4; i++)
    {
        Key += GetRandomCharacter(enCharType::CapitalLatter);
    }
    return Key;
}

void CreatKey (int Number, short Length) {

    string Key = "";
    for (size_t i = 1; i <= Number; i++)
    {
        for (size_t j = 1; j <= Length; j++)
        {
            if (j == Length) {
                Key += CreatWord();
                break;
            }
            Key += CreatWord() + "-";
        }
        cout << "Key[" << i << "] : " << Key << endl;
        Key = "";
    }
    
}
int main() {
     
    srand((unsigned)time(0));
    CreatKey(ReadPositiveNumber("Please enter How many keys to generate?"), 4);
    return 0;
}