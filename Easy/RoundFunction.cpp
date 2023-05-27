#include <iostream>
#include <cmath>

using namespace std;

float GetFractionPart (float Number) {

    return Number - int(Number);
}

int MyRound (float Number) {

    int IntPart = int(Number);
    float FractionPart = GetFractionPart(Number);

    if (abs(FractionPart) >= .5) {

        if (Number > 0)
            return ++IntPart;
        return --IntPart;
    }
    else {
        return IntPart;
    }
}
int main() {

    cout << MyRound(1.4) << endl;
    cout << round(1.5) << endl;
    return 0;
}