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

void CreatArray (int array[],int array2[], int size) {

    for (size_t i = 0; i < size; i++)
    {
        array[i] = RandomNumber(1, 100);
        array2[i] = RandomNumber(1, 100);
    }
}

void PrintArray (int array[], int array2[], int size) {

    cout << "Sum of array1 and array2 element :\n";
    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] + array2[i] << " ";
    }
    cout << endl;
}
int main() {
    srand((unsigned)time(0));

    int size = ReadPositiveNumber("Please enter size of array?");
    int array[size] = {};
    int array2[size] = {};
    CreatArray(array, array2, size);
    PrintArray(array, array2, size);

    return 0;
}