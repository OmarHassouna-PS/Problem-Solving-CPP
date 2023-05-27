#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<iomanip>

using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

string ReadClientAccountNumber () {

    string ClientAccountNumber = "\0"; 
    cout << "Please Enter Account Number Client? ";
    cin >> ClientAccountNumber;

    return ClientAccountNumber;
}

vector <string> SplitString (string str, string Delim) {

    vector <string> vWord;
    short pos = 0;
    string sWord = "\0";
    
    while ((pos = str.find(Delim)) != std::string::npos) {

        sWord = str.substr(0, pos);
        if (sWord != "") {
            vWord.push_back(sWord);
        }
        str.erase(0, pos + Delim.length()); 
    }

    if (str != "") {
        vWord.push_back(str);
    }
    return vWord;
}

stClient ConvertLineToStructForClient (string LineRecord, string Delim) {

    stClient Client;
    vector <string> vClientData = SplitString(LineRecord, Delim);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

vector <stClient> LoadClientsDataFromFile (string FileName, string Delim) {

    vector <stClient> vClients;
    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) { 

        string Line = "\0";
        stClient Client; 

        while (getline(MyFile, Line)) {
            
            Client = ConvertLineToStructForClient(Line, Delim);
		    vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void ShowClientData (stClient Client) {

    cout << "\nThe Following are the client details:\n\n";
    cout << "Account Number  : " << Client.AccountNumber << endl;
    cout << "Pin Code        : " << Client.PinCode << endl;
    cout << "Name            : " << Client.Name << endl;
    cout << "Phone           : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.AccountBalance << endl;
}

bool SearchByAccountNumber (vector <stClient> vClients, string AccountNumber, stClient& Client) {

    for (stClient vClient : vClients)
    {
        if (vClient.AccountNumber == AccountNumber)
        {
            Client = vClient;
            return true;
        }
    }
    return false;
    
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

void DeleteClientFromFile (vector <stClient> vClients, string AccountNumber, stClient Client, string Delim) {

    fstream MyFile;

    MyFile.open("ClientData.txt", ios::out ); 
    
    for (stClient vClient : vClients)
    {
        if (vClient.AccountNumber != AccountNumber)
        {
            MyFile << ConvertRecordToLineForClient(vClient, Delim) << endl;
        }
    }
    MyFile.close();
    cout << "\n\nClient Deleted Successfully." << endl;
}

int main() {

    vector <stClient> vClients = LoadClientsDataFromFile("ClientData.txt", "#//#");
    string AccountNumber = ReadClientAccountNumber();

    char CheckDeleteClient = 'N';
    stClient Client;


    if ( SearchByAccountNumber(vClients, AccountNumber, Client) ) {
        ShowClientData(Client);
    }
    else {
        cout << "Client with Account Number (" << AccountNumber << ") Not Found!" << endl;
        return 0;
    }

    cout << "\nAre you sure you delete this client Y/N ? ";
    cin >> CheckDeleteClient;

    if ( CheckDeleteClient == 'Y' || CheckDeleteClient == 'y' )
    {
        DeleteClientFromFile(vClients, AccountNumber, Client, "#//#");
    }
    else {
        cout << "Operation cancelled.";
    }

    return 0;
}

/* 
A150#//#1111#//#omar#//#077821321#//#5000.000000
B555#//#444#//#ahmad#//#0788654151#//#90000.000000
C344#//#5223#//#ali#//#078513514#//#7000.00000
C344#//#5223#//#ali#//#078513514#//#7000.00000 
*/