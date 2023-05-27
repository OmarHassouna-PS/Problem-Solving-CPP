#include <iostream>
#include<string>

using namespace std;

string GetString (string Message = "" ) {
    
    string text = "\0";
    cout << Message << endl;
    getline(cin, text); 

    return text;
}
short CountWordsInString (string str, string Delim = " ") {

    string sWord; 
    short pos = 0, Counter = 1;

    // se find() function to get the position of the delimiters
    
    while ((pos = str.find(Delim)) != std::string::npos) {

        sWord = str.substr(0, pos);
        if (sWord != "") {
            Counter++;
        }
        str.erase(0, pos + Delim.length()); 
        // erase() until position and move to next word.
    }
    return Counter;
}

int main() {

    // string str = GetString("Please Enter yore String?");

    cout << "Yore string words are: ";

    cout << CountWordsInString ("omar omar ahmad") << endl;
    
    return 0;
}