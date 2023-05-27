#include <iostream>
using namespace std;

string ReadName (string Message) {

    string Name = "";
    cout << Message << endl;
    getline(cin, Name);
    return Name;
}
string EncryptionName (string Name) {

    int Counter = 0;
    string NameEncryption = "";

    while (Name[Counter] != '\0')
    {
        if (int(Name[Counter - 65]) >= 65 || int(Name[Counter - 65]) <= 90) {
            NameEncryption += char(int((Name[Counter] + 3 - 65) + 65));
        }
        else {
            NameEncryption += char(int((Name[Counter] + 3 - 97) + 97));
        }
        Counter++;
    }
    return NameEncryption;
}

string DecryptName (string EncryptionName) {
    
    int Counter = 0;
    string Name = "";

    while (EncryptionName[Counter] != '\0')
    {
        if (int(EncryptionName[Counter - 65]) >= 65 || int(EncryptionName[Counter - 65]) <= 90)
            Name += char(int((EncryptionName[Counter] - 3 + 65) - 65));
        else
            Name += char(int((EncryptionName[Counter] - 3 + 97) - 97));
        Counter++;
    }
    return Name;

}

void PrintResult (string Name) {
    
    cout << "Before Encryption: " << Name << endl;
    cout << "After Encryption: " << EncryptionName(Name) << endl;
    cout << "Before Encryption: " << DecryptName(EncryptionName(Name)) << endl;
}

int main() {

    PrintResult(ReadName("Please enter your Name ? "));

    return 0;
}