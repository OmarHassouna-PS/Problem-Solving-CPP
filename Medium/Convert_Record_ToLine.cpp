#include <iostream>
#include<string>
using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

void ReadNewClient ( stClient& Client) {

    cout << "Enter Account Number ? ";
    getline(cin, Client.AccountNumber);
    cout << "Enter PinCode ? ";
    getline(cin, Client.PinCode);
    cout << "Enter Name ? ";
    getline(cin, Client.Name);
    cout << "Enter Phone ? ";
    getline(cin, Client.Phone);
    cout << "Enter Account Balance ? ";
    cin >> Client.AccountBalance;
}

string ConvertRecordToLineForClient(stClient ClientData, string Delim) {

    string stClientRecord = "\0";

    stClientRecord  += 
    ClientData.AccountNumber + Delim +
    ClientData.PinCode       + Delim +
    ClientData.Name          + Delim +
    ClientData.Phone         + Delim +
    to_string(ClientData.AccountBalance);

    return stClientRecord ;
}

int main() {

    stClient Client;

    cout << "Please Enter Client Data:\n";

    ReadNewClient(Client);

    cout << "Client Record for saving is:\n";

    cout << ConvertRecordToLineForClient(Client, "#//#");

    
    return 0;
}