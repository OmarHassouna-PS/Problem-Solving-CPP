#include <iostream>
using namespace std;

string ReadPassword (string Message) {

    string Password = "";
    cout << Message << endl;
    cin >> Password;
    return Password;
}
void PrintFromAAAtoZZZ (string Password) {

    int Counter = 0;
    string PasswordTest = "";
    for (size_t i = 0; i < 26; i++)
    {
        for (size_t y = 0; y < 26; y++)
        {
            for (size_t x = 0; x < 26; x++)
            {
                PasswordTest += char(i + 65);
                PasswordTest += char(y + 65);
                PasswordTest += char(x + 65);
                
                Counter++;

                if (PasswordTest == Password) {
                    cout << "Password is " << PasswordTest << "\n Found after " << Counter << " Trial(s)";
                    return;
                }
                PasswordTest = "";
            }
        }
    }
}
int main() {

    PrintFromAAAtoZZZ(ReadPassword("Please enter your Password ? "));

    return 0;
}