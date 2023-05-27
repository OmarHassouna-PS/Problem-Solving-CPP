#include <iostream>
#include <math.h>
using namespace std;

const float PI = 3.14159;

float GetInfoOfRadius() {

    float R;
    cout << "Please enter radius \n";
    cin >> R;
    return R;
}

float CircleAreaByRadius(float R) {
    
    return PI * pow(R, 2);
}

void PrintResult(float Area) {

    cout << " \n The area of the circle is " << Area << endl;
}
int main() {

    PrintResult(CircleAreaByRadius(GetInfoOfRadius()));
    return 0;
} 