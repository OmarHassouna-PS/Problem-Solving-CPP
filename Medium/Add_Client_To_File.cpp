#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

stClient ReadNewClient () {

    stClient Client;

    cout << "Enter Account Number ? ";
    getline(cin >> ws, Client.AccountNumber);
    cout << "Enter PinCode ? ";
    getline(cin, Client.PinCode);
    cout << "Enter Name ? ";
    getline(cin, Client.Name);
    cout << "Enter Phone ? ";
    getline(cin, Client.Phone);
    cout << "Enter Account Balance ? ";
    cin >> Client.AccountBalance;

    return Client;
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

void AddClientFromFile (string ClientData) {

    fstream MyFile;

    MyFile.open("ClientData.txt", ios::out | ios::app);

    if (MyFile.is_open()) { 
        MyFile << ClientData << endl;
        MyFile.close();
    }
}

int main() {

    stClient Client;
    char AddMore = 'Y';
    do
    {
        cout << "Adding New Client:\n\n";
        AddClientFromFile(ConvertRecordToLineForClient(ReadNewClient(), "#//#"));

        cout << "\nClient Added Successfully, do you want to add more clients? ";
        cin >> AddMore;
        
    } while (AddMore == 'y' || AddMore == 'Y');
    
    return 0;
}