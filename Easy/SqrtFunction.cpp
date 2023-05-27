#include <iostream>
#include <cmath>

using namespace std;

float MySqrt (float Number) {

    int L = 1, R = Number;

    while (L < R) {
        int mid = (L+R) / 2;
        int temp = Number/mid;
        if (temp == mid)
            return mid;
        else if (temp < mid)
            R = mid;
        else 
            L = mid +1;
    }
    return L -1; 
}

int main() {

    cout << MySqrt(32) << endl;
    cout << sqrt(32) << endl;
    return 0;
}