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

string JoinString (vector <string> vNames, string delim) {

    string S1 = "\0";

	for (string& s : vNames) {

        S1 = S1 + s + delim;
    }
    return S1.substr(0, S1.length()-delim.length());
}

int main() {

    // string str = GetString("Please Enter yore String?");

    vector <string> vNames = { "Omar", "Ahmad", "Ali", "Mohammed" };

    cout << JoinString(vNames, ",") << endl;
    
    return 0;
}