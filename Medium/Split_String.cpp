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

vector <string> Split (string str, string delim) {

    vector <string> vWord;

    short pos = 0;
    string sWord = "\0";

    
    while ((pos = str.find(delim)) != std::string::npos) {

        sWord = str.substr(0, pos);
        if (sWord != "") {
            vWord.push_back(sWord);
        }
        str.erase(0, pos + delim.length()); 
    }

    if (str != "") {
        vWord.push_back(str);
    }
    return vWord;
}

void PrintVector (vector <string> Vstr) {

    vector <int>::iterator i;
    short Count = 0;
	for (string &i : Vstr) {

        cout << i << "\n";
        Count++;
    }
    cout << "Tokens = " << Count << endl;
}

int main() {

    // string str = GetString("Please Enter yore String?");

    PrintVector(Split("omar omar ahmad", " "));
    
    return 0;
}