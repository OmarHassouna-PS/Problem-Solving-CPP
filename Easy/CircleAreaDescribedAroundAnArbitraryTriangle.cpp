#include <iostream>
#include <math.h>
using namespace std;

const float PI = 3.14159;

void ReadTriangleData(float& A, float& B, float& C) {

    cout << "Please enter triangle side -A- \n";
    cin >> A;

    cout << "Please enter triangle base -B- \n";
    cin >> B;

    cout << "Please enter triangle side -C- \n";
    cin >> C;
}

float CircleAreaByATriangle(float A, float B, float C) {
    
    int P = (A + B + C) / 2;
    return PI * pow(((A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)))),2);
}

void PrintResult(float Area) {

    cout << " \n The area of the circle is " << Area << endl;
}
int main() {

    float A, B, C;
    ReadTriangleData(A, B, C);
    PrintResult(CircleAreaByATriangle(A, B, C));
    return 0;
} 