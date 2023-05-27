#include <iostream>
#include <math.h>
using namespace std;

const float PI = 3.14159;

void ReadTriangleData(float& A, float& B) {

    cout << "Please enter triangle side -A- \n";
    cin >> A;

    cout << "Please enter triangle base -B- \n";
    cin >> B;
}

float CircleAreaByITriangle(float A, float B) {
    
    return PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));
}

void PrintResult(float Area) {

    cout << " \n The area of the circle is " << Area << endl;
}
int main() {

    float A, B;
    ReadTriangleData(A, B);
    PrintResult(CircleAreaByITriangle(A, B));
    return 0;
} 