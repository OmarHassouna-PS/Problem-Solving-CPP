#include <iostream>
#include <cmath>

using namespace std;

float GetFractionPart (float Number) {

    return Number - int(Number);
}

int MyCeil (float Number) {

    if (abs(GetFractionPart(Number)) > 0) {

        if (Number > 0)
            return int(Number) + 1;
        else
            return int(Number);
    }
    else {
        return Number;
    }
}
int main() {

    cout << MyCeil(10) << endl;
    cout << ceil(10.7) << endl;
    return 0;
}