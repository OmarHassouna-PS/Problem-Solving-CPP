#include <iostream>
using namespace std;

string GetName() {

    string Name = "";
    cout << "Please enter your name? \n";
    getline(cin, Name);
    return Name;
}

void PrintName(string Name) {

    cout << "Yore Name is " << Name << endl;

}
int main() {

    PrintName(GetName());
    return 0;
}