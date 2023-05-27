#include <iostream>
using namespace std;

int main() {

    short arr[5] = {5, 3, 1};
    short counter = 2;
    for (short i = 1; i <= 5; i++) {

        if (i == arr[0] || i == arr[1] || i == arr[2]){
            counter++;
            continue;
        }
        arr[counter] = i;
    }
    
    for (short j = 0; j < 5; j++) {
        cout << arr[j] << endl;
    }
    
    
    return 0;
}