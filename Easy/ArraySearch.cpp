#include <iostream>
using namespace std;

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


void CreatArray (int array[], int size) {

    for (size_t i = 0; i < size; i++)
    {
        array[i] = RandomNumber(1, 100);
    }
}

int SearchNumberInArray (int array[], int size, int NumberSearch) {

    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == NumberSearch)
        {
            return i+1;
        }
    }
    return 0;
    
}
void PrintArray (int array[], int size) {

    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

}

void PrintResult (int Result, int NumberSearch) {

    if (Result) {
        cout << "Number you are looking for is: " << NumberSearch << endl;
        cout << "The number found at position: " << Result - 1 << endl;
        cout << "The number found its order: " << Result << endl;
    }
    else {

        cout << "Number yor are looking for is: " << NumberSearch << endl;
        cout << "The number is not found\n"; 
    }
}

int main() {
    srand((unsigned)time(0));

    int size = ReadPositiveNumber("Please enter size of array?");
    int array[size] = {};
    CreatArray(array, size);
    PrintArray(array, size);
    int NumberSearch = ReadPositiveNumber("Please enter number to search for?");
    PrintResult(SearchNumberInArray(array, size, NumberSearch), NumberSearch);

    return 0;
}