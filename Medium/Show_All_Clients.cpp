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

void PrintClientsData (vector <stClient> vClients) {

    cout << "\t\t\t\tClient List (" << vClients.size() << ")" << " Client(s).";
    cout << "\n____________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) << "AccountNumber";
    cout << "| " << left << setw(10) << "PinCode";
    cout << "| " << left << setw(30) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "AccountBalance";
    cout << "\n____________________________________________________________________________________________\n\n";

    for (stClient Client : vClients)
    {
        cout << "| " << left << setw(15) << Client.AccountNumber;
        cout << "| " << left << setw(10) << Client.PinCode;
        cout << "| " << left << setw(30) << Client.Name;
        cout << "| " << left << setw(12) << Client.Phone;
        cout << "| " << left << setw(12) << Client.AccountBalance;
        cout << "\n";
    }
    cout << "\n___________________________________________________________________________________________";
}

int main() {

    vector <stClient> vClients = LoadClientsDataFromFile("ClientData.txt", "#//#");

    PrintClientsData(vClients);
    
    return 0;
}