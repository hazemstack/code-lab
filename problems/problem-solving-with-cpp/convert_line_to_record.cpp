#include <iostream>
#include <string>
using namespace std;

struct ClientData
{
    string accountNum;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
};

ClientData convertLineToRecord(string line, string delim)
{
    ClientData client;
    int pos = 0;
    string token;
    int fieldCount = 0;

    while ((pos = line.find(delim)) != string::npos)
    {
        token = line.substr(0, pos);

        switch (fieldCount)
        {
        case 0:
            client.accountNum = token;
            break;

        case 1:
            client.pinCode = token;
            break;

        case 2:
            client.name = token;
            break;

        case 3:
            client.phone = token;
            break;
        }

        line.erase(0, pos + delim.length());
        fieldCount++;
    }

    client.accountBalance = stod(line);
    return client;
}

void printClientData(ClientData client)
{
    cout << "Account Number : " << client.accountNum << endl;
    cout << "Pin Code       : " << client.pinCode << endl;
    cout << "Name           : " << client.name << endl;
    cout << "Phone          : " << client.phone << endl;
    cout << "Account Balance: " << client.accountBalance << endl;
}

int main()
{
    string line = "A100#//#4321#//#Hazem El-Saeed#//#01098765432#//#4000";

    cout << "\nLine Record:\n";
    cout << "-----------\n";
    cout << line << endl;

    ClientData client = convertLineToRecord(line, "#//#");

    cout << "\nClient Record:\n";
    cout << "-------------\n";
    printClientData(client);
    cout << endl;

    return 0;
}
