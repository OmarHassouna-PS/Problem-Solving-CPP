#include <iostream>
using namespace std;

void PrintFromAAAtoZZZ () {

    for (size_t i = 0; i < 26; i++)
    {
        for (size_t y = 0; y < 26; y++)
        {
            for (size_t x = 0; x < 26; x++)
            {
                cout << char(i + 65) << char(y + 65) << char(x + 65) << endl;
            }
        }
    }
}
int main() {

    PrintFromAAAtoZZZ();

    return 0;
}