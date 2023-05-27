#include <iostream>
#include<string>
#include<vector>

using namespace std;

string ReverseWords (string str, char delim) {
    
    string S1 = "\0";
    for (short i = str.length(); i >= 0; i--)
    {
        if (str[i] == delim) {
            S1 += str.substr(i, str.length() - i );
            str.erase(i, str.length() - i);
        }
        else if (i == 0) {
            S1 += " " + str.substr(i, str.length() - i);
        }
    }
    return S1.erase(0,1);
}

vector <string> SplitString (string str, string delim) {

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

string ReverseWordsInString(string S1) {

    vector<string> vString;
    string S2 = "";
    vString = SplitString(S1, " "); 
    vector <string>::iterator iter = vString.end();

    while (iter != vString.begin()) {
        
        --iter;
        S2 += *iter + " ";
    }
    
    S2 = S2.substr(0, S2.length() - 1); //remove last space.

    return S2;
    
}

int main() {

    string Word = "Omar Ahmad Ali Mohammed";

    // cout << ReverseWords(Word, ' ') << endl;

    cout << "\n" << ReverseWordsInString(Word);
    return 0;
}