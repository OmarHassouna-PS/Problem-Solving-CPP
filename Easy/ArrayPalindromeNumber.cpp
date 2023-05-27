#include <iostream>
using namespace std;

void FillArray (int array[]) {

    array[0] = 10, array[1] = 20, array[2] = 30, array[3] = 20, array[4] = 10;
}


bool IsPalindromeNumber (int arr[], int size) {

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] != arr[size - i - 1])
        {
            return false;
        }
    }
    return true;
}

void PrintArray (int array[], int size) {

    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

}

int main() {
    int size = 5, arr[size];

    FillArray(arr);

    PrintArray(arr, size);

    if(IsPalindromeNumber(arr, size)) {
        cout << "Yes array is palindrome\n";
    }
    else {
        cout << "No array is not palindrome\n";
    }
    


    
    return 0; 
}