#include <iostream>
#include <math.h>
using namespace std;

void GetInfoOfArea(float& a, float& b) {

    cout << "Please enter rectangle side -A- \n";
    cin >> a;
    cout << "Please enter rectangle diagonal -B- \n";
    cin >> b;
}

float CalculatRectangleArea(float a, float b) {
    
    return a * sqrt(pow(b,2) - pow(a,2));
}

void PrintResult(float RectangleArea) {

    cout << " \n Rectangle area is " << RectangleArea << endl;
}
int main() {

    float a, b;
    GetInfoOfArea(a, b);
    PrintResult(CalculatRectangleArea(a, b));
    return 0;
} 