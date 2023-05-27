#include <iostream>
using namespace std;

int main() {

    int arr[] = {9, 2, 6, 3, 7, 8}; 

    for (int i = 0; i < 6; i++) {

        cout <<  "[" << i << "] - "  << &arr[i] << endl;       //  عناوين العناصر 
    }

    cout << "\nAddress array : " << arr << endl;              //  عنوان المصفوفة 


    cout << "Next address  : " << (&arr + 1) << endl;         //  اول عنوان بعد عناوين المصفوفة


    cout << "Size of Array : " << *(&arr + 1) - arr << endl;  //  الفرق بين اول اخر عنوان بعد عنواوين المصفوفة ناقص عنوان المصفوفة
    
    //  int len = sizeof(arr)/sizeof(arr[0]);

    const char* name = "Ali";
    cout<< name[16];

}