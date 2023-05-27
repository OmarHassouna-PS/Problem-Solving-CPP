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

void Swap (int& A, int& B ) {

    int Tmp = A;
    A = B;
    B = Tmp;
}

void CreatArray (int array[], int size) {

    for (size_t i = 0; i < size; i++)
    {
        array[i] = i+1;
    }
}

void ShuffleArray (int array[], int size) {

    for (size_t i = 0; i < size; i++)
    {
        Swap(array[RandomNumber(1,size) - 1], array[RandomNumber(1,size) - 1]);
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
    CreatArray(array, size);

    cout << "Array element before shuffle :\n\n";
    PrintArray(array, size);

    ShuffleArray(array, size);
    cout << "Array element after shuffle :\n";
    PrintArray(array, size);

    return 0;
}