#include <iostream>
#include<string>

using namespace std;

string RemovePunctuations (string str) {
    
    string S1 = "\0";
    for (short i = 0; i < str.length(); i++)
    {
        if (ispunct(str[i])) {
            str.erase(i, 1);
        }
    }
    return str;
}

int main() {

    string Word = "Omar, Ahmad: Ali' Mohammed.";

    cout << RemovePunctuations(Word);
    return 0;
}