#include <iostream>
#include<string>
#include<vector>

using namespace std;

string GetString (string Message = "" ) {
    
    string text = "\0";
    cout << Message << endl;
    getline(cin, text); 

    return text;
}

string TrimLift (string str, char delim) {

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != delim)
        {
            return str.substr(i, str.length() - i);
        }
    }
    return "";

}

string TrimRight (string str, char delim) {
    
    for (short i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] != delim) {
            return str.substr(0, i + 1);
        }
    }
    return "";
}

int main() {

    // string str = GetString("Please Enter yore String?");
    string Name = "     om ar     ";
    cout << TrimLift(Name, ' ') << endl;
    cout << TrimRight(Name, ' ') << endl;
    
    return 0;
}