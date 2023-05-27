#include <iostream>
#include<string>

using namespace std;

string GetString (string Message = "" ) {
    
    string text = "\0";
    cout << Message << endl;
    getline(cin, text); 

    return text;
}
void PrintWordsEndl (string str) {

/*     string strCut = "\0";
    for (size_t i = 0; i < str.length() + 1 ; i++)
    {
        if (str[i] != ' ' && i != str.length()) {
            strCut += str[i];
        }
        else {
            cout << strCut << endl;
            strCut = "\0";
        }
    }  */

    string delim = " "; // delimiter
    short pos = 0;
    string sWord;

    // se find() function to get the position of the delimiters
    
    while ((pos = str.find(delim)) != std::string::npos) {

        sWord =str.substr(0, pos);
        if (sWord !="") {
            cout << sWord << endl;
        }
        str.erase(0, pos + delim.length()); 
        // erase() until position and move to next word.
    }
    if (str!="") {
        cout <<str<< endl; // it print last word of the string.
    } 
}

int main() {

    // string str = GetString("Please Enter yore String?");

    cout << "Yore string words are:\n";

    PrintWordsEndl ("   omar omar ahmad    ");
    
    return 0;
}