#include <iostream>
using namespace std;

short arraySum(short arr[], short size)
{ 
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
  }
  return sum;
}

short diffrenceBetween2Arrays(short arr1[], short arr2[], short  size1, short size2)
{

  short sum1 = arraySum(arr1, size1);
  short sum2 = arraySum(arr2, size2);

    return (sum1 >= sum2) ? sum1 - sum2 : sum2 - sum1;

}

void printArr(short arr[], short size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << "  ";
  }
  cout << endl;

}

int main()
{
  short arr1[] = { 1,2,3,4,5,9};
  short arr2[] = { 1,2,3,35,4,5 ,9};
  
  short size1 = sizeof(arr1) / sizeof(arr1[0]);

  short size2 = sizeof(arr2) / sizeof(arr2[0]);

  printArr(arr1, size1);

  cout << endl;

  printArr(arr2, size2);

  cout << endl;
  cout << "the diffrence element in arrays is : " << diffrenceBetween2Arrays(arr1, arr2, size1, size2);

  return 0;

}