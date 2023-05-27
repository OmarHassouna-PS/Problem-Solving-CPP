#include <iostream>

#include <math.h>
using namespace std;

const float PI = 3.14159;

float ReadCircumference() {

    float L;
    cout << "Please enter Circumference of the circle area  \n";
    cin >> L;
    return L;
}

float CircleAreaByCircumference(float L) {
    
    return pow(L, 2) / (4 * PI);
}

void PrintResult(float Area) {

    cout << " \n The area of the circle is " << Area << endl;
}
int main() {

    PrintResult(CircleAreaByCircumference(ReadCircumference()));
    return 0;
} 