#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To) {

    return rand()% (To - From + 1) + From;
}

int main() {
     
    srand((unsigned)time(0));
    cout << RandomNumber(20, 50) << endl;
    cout << RandomNumber(20, 50) << endl;
    cout << time(0) << endl;

    return 0;
}