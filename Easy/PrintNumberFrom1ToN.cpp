#include <iostream>
using namespace std;

short ReadNumber() {

    short N;
    cout << "Please enter number  \n";
    cin >> N;
    return N;
}

void PrintRangFrom1toN (short N) {

     for (size_t i = 1; i <= N; i++)
    {
        cout << i << endl;
    }


/*     short Counter = 1;
    while (N >= Counter)
    {
        cout << Counter << endl;
        Counter++;
    } */


/*     short Counter = 1;
    do {
        cout << Counter << endl;
        Counter++;
    } 
    while (N >= Counter);
 */    

/*      for (size_t i = N; i >= 1; i--)
    {
        cout << i << endl;
    } */


}
int main() {

    PrintRangFrom1toN(ReadNumber());
    return 0;
}