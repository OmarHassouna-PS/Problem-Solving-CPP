#include <iostream>
#include <math.h>
using namespace std;

const float PI = 3.14159;

float ReadDiameter() {

    float D;
    cout << "Please enter Diameter \n";
    cin >> D;
    return D;
}

float CircleAreaByDiameter(float D) {
    
    return (PI * pow(D, 2)) / 4;
}

void PrintResult(float Area) {

    cout << " \n The area of the circle is " << Area << endl;
}
int main() {

    PrintResult(CircleAreaByDiameter(ReadDiameter()));
    return 0;
} 