#include <iostream>
#include <math.h>
using namespace std;

void GetInfoOfArea(float& a, float& h) {

    cout << "Please enter triangle base -A- \n";
    cin >> a;
    cout << "Please enter triangle height -h- \n";
    cin >> h;
}

float TriangleArea(float a, float h) {
    
    return h * (a / 2);
}

void PrintResult(float RectangleArea) {

    cout << " \n Rectangle area is " << RectangleArea << endl;
}
int main() {

    float a, h;
    GetInfoOfArea(a, h);
    PrintResult(TriangleArea(a, h));
    return 0;
} 