#include <iostream>
using namespace std;

void PrintHeader () {
    cout <<"\n\n\t\t\tMultipliaction Table From 1 to 10\n\n";
    cout << "\t\t1" << "\t2" << "\t3" << "\t4" << "\t5" << "\t6" << "\t7" << "\t8" << "\t9" << "\t10\n";
    cout << "___________________________________________________________________________________________\n";
}

void PrintMultipliactionTable () {

    PrintHeader();

    for (size_t i = 1; i <= 10; i++)
    {
        cout << i << "\t|";
        for (size_t j = 1; j <= 10; j++)
        {
            cout << "\t" << i * j;
        }
        cout << endl;
    }
    
}
int main() {

    PrintMultipliactionTable();
    return 0;
}