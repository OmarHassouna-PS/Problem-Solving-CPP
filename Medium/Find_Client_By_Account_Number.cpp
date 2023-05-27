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

void SearchByAccountNumber (vector <stClient> vClients, string AccountNumber) {

    for (stClient Client : vClients)
    {
        if (Client.AccountNumber == AccountNumber)
        {
            return ShowClientData(Client);
        }
    }
    cout << "Client with Account Number (" << AccountNumber << ") Not Found!" << endl;
}

int main() {

    vector <stClient> vClients = LoadClientsDataFromFile("ClientData.txt", "#//#");
    string AccountNumber = "\0";

    cout << "Please Enter Account Number Client? ";
    cin >> AccountNumber;

    SearchByAccountNumber(vClients, AccountNumber);

    return 0;
}