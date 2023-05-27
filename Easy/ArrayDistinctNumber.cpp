#include <iostream>
using namespace std;

void FillArray (int array[100], int& arrLength) {
    arrLength = 10;
    array[0] = 10, array[1] = 10, array[2] = 10, array[3] = 50, array[4] = 50,
    array[5] = 70,array[6] = 70, array[7] = 70,array[8] = 70, array[9] = 90;
}

void AddArrayElement (int Number, int array[100], int& arrLength) {
    arrLength++;
    array[arrLength - 1] = Number;
}

int SearchNumberInArray (int array[100], int size, int NumberSearch) {

    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == NumberSearch)
        {
            return i+1;
        }
    }
    return 0;
}

bool IsNumberInArray(int Number, int array[], int arrLength) {
    return SearchNumberInArray(array, arrLength, Number) != 0;
}

void CreatArrayDistinct (int array[100], int array2[100], int size, int& DestinationLength) {

    for (size_t i = 0; i < size; i++) {
        if (!IsNumberInArray(array[i], array2, DestinationLength)) {   

            AddArrayElement(array[i], array2, DestinationLength);    
        }   
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

    int arrSource[100], SourceLength = 0, arrDestination[100], DestinationLength = 0;
    FillArray(arrSource, SourceLength);
    cout << "\nArray 1 elements:\n";
    PrintArray(arrSource, SourceLength);
    CreatArrayDistinct(arrSource, arrDestination, SourceLength, DestinationLength);
    cout << "\nArray 2 distinct elements:\n";
    PrintArray(arrDestination, DestinationLength);
    return 0; 
}