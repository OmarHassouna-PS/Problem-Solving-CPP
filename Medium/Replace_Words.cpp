#include <iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

string ReplaceWords (string& str, char delim, string StrToReplace, string strReplaceTo) {
    
    string TempStr = "\0";
    string CopeStr = str;
    transform(StrToReplace.begin(), StrToReplace.end(), StrToReplace.begin(), ::toupper);

    short Count = 0, LengthStr = str.length(), LengthStrToReplace = StrToReplace.length(), LengthStrReplaceTo = strReplaceTo.length();

    for (short i = 0; i <= LengthStr; i++)
    {
        transform(TempStr.begin(), TempStr.end(), TempStr.begin(), ::toupper);
        if (str[i] != delim && i != LengthStr && TempStr != StrToReplace) {
            TempStr += str[i];
            continue;
        }
        else if (TempStr == StrToReplace ) {
            (Count == 0) ? CopeStr.erase(i-LengthStrToReplace, LengthStrToReplace) : CopeStr.erase(i - (LengthStrReplaceTo * Count) - LengthStrToReplace, LengthStrToReplace);
            (Count == 0) ? CopeStr.insert(i-LengthStrToReplace, strReplaceTo)      : CopeStr.insert(i - (LengthStrReplaceTo * Count) - LengthStrToReplace, strReplaceTo);
            Count++;
            TempStr = "";
        }
        else {
            TempStr = "";
        }
    }
    return CopeStr;
}

string ReplaceWords2 (string& str, string StrToReplace, string strReplaceTo) {

	short pos = 0;
	while ((pos = str.find(StrToReplace)) != std::string::npos)
	{
	   
		str.erase(pos,StrToReplace.length());
		str.insert(pos, strReplaceTo);
    }
    return str;
}

string ReplaceWords3 (string& str, string StrToReplace, string strReplaceTo)  {

    short pos = str.find(StrToReplace);
    while (pos != std::string::npos) {

        str = str.replace(pos, StrToReplace.length(), strReplaceTo);
        pos = str.find(StrToReplace);//find next
        
    }
    return str;
}

int main() {

    string Word = "Welcome to Jordan , Jordan is a nice country";
    cout << ReplaceWords(Word, ' ', "Jordan", "USA") << endl;
	cout << ReplaceWords2(Word, "Jordan", "USA") << endl;
    cout << ReplaceWords3 (Word, "Jordan", "USA") << endl;

    return 0;
}