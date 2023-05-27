#include <iostream>
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

void CreatKeyInArray (short Length, string array[], int size) {

    string Key = "";
    for (size_t i = 1; i <= size; i++)
    {
        for (size_t j = 1; j <= Length; j++)
        {
            if (j == Length) {
                Key += CreatWord();
                break;
            }
            Key += CreatWord() + "-";
        }
        array[i-1] = Key;
        Key = "";
    }
}

void PrintArrayKey (string array[], int size) {

    for (size_t i = 0; i < size; i++)
    {
        cout << "Array[" << i + 1 << "] : " << array[i] << endl;
    }

}

int main() {
    srand((unsigned)time(0));

    int size = ReadPositiveNumber("Please enter size of array?");
    string array[size] = {};
    CreatKeyInArray(4, array, size);

    cout << "Array elements :\n\n";
    PrintArrayKey(array, size);

    return 0;
}