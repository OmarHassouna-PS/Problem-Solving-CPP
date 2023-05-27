#include <iostream>
#include<string>
#include<vector>

using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

void ReadLineRecord (string& LineRecord) {

    cout << "Line Record is:\n";
    getline(cin, LineRecord);
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

void FileDataInStruct (stClient& Client, string LineRecord, string Seperator = "#//#") {

    vector <string> vClientData = SplitString(LineRecord, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);
}

void ShowClientData (stClient Client) {

    cout << "Account Number  : " << Client.AccountNumber << endl;
    cout << "Pin Code        : " << Client.PinCode << endl;
    cout << "Name            : " << Client.Name << endl;
    cout << "Phone           : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.AccountBalance << endl;

}

int main() {
    string LineRecord = "A150#//#1234#//#Omar ahmad#//#0778788014#//#5270.0000";
    // ReadLineRecord(LineRecord);

    stClient Client;
    FileDataInStruct(Client, LineRecord);

    cout << "The Following is the extracted client record:\n\n";
    ShowClientData(Client);
    
    return 0;
}