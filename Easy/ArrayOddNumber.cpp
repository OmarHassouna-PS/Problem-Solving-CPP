#include <iostream>
#include <time.h>

using namespace std;

int RandomNumber(int From, int To) {

    return rand()% (To - From + 1) + From;
}

void CreatArray (int array[], int size) {

    for (size_t i = 0; i < size; i++)
    {
        array[i] = RandomNumber(1, 100);
    }
}

int CountOddNumber (int arr[], int size) {

    int Counter = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0)
        {
            Counter++;
        }
    }
    return Counter;
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

    int size = 10, arr[size];

    CreatArray(arr, size);

    PrintArray(arr, size);
    
    cout << "Odd Number count is : " << CountOddNumber(arr, size) << endl;
    


    
    return 0; 
}