#include <iostream>
#include <time.h>

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

void CopyArrayInReverseOrder (int array[], int array2[], int size) {

    for (size_t i = 0; i < size; i++)
    {
        array2[i] = array[size-i-1];
    }
    
}

void PrintArray (int array[], int size) {

    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    
}

int main() {
    srand((unsigned)time(0));

    int size = ReadPositiveNumber("Please enter size of array?");
    int array[size] = {};
    int array2[size] = {};
    CreatArray(array, size);

    cout << "Array 1 elements :\n";
    PrintArray(array, size);

    CopyArrayInReverseOrder(array, array2, size);
    cout << "\nArray 2 elements after copying array 1 in reversed order :\n";
    PrintArray(array2, size);

    return 0;
}