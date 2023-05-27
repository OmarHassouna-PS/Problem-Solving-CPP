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

void CreatArray (int array[], int size) {

    int CheckNumber = 0;
    cout << "Enter array elements:\n";
    for (size_t i = 0; i < size; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> array[i];
    }
}

int LookupArray (int array[], int size, int CheckNumber) {

    int counter = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == CheckNumber)
            counter++;
    }
    return counter;
}

void PrintArray (int array[], int counter, int size, int CheckNumber) {

    cout << "Original array: ";
    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n" << CheckNumber << " is repeated " << counter << " time(s)\n";
}
int main() {

    int size = ReadPositiveNumber("Please enter size of array?");
    int array[size] = {};
    CreatArray(array, size);
    int CheckNumber = ReadPositiveNumber("\nEnter the number you want to check: ");
    int CheckNumberRisealt = LookupArray(array, size, CheckNumber);
    PrintArray(array, CheckNumberRisealt, size, CheckNumber);

    return 0;
}