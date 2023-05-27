#include <iostream>
#include <cmath>

using namespace std;

int MyAbs (int Number) {

    if (Number < 0)
        return Number * -1;
    return Number;

}
int main() {

    cout << MyAbs(-10) << endl;
    cout << abs(-10) << endl;
    return 0;
}