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

void PrintArray (int array[],int size) {

    cout << "Array Element : ";
    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}
int main() {
    srand((unsigned)time(0));

    int size = ReadPositiveNumber("Please enter size of array?");
    int array[size] = {};
    CreatArray(array, size);
    PrintArray(array, size);

    return 0;
}