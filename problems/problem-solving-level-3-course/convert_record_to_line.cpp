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

void readClientData(ClientData &client)
{
    cout << "Enter the Account Number: ";
    cin >> client.accountNum;

    cout << "Enter the Pin Code: ";
    cin >> client.pinCode;

    cin.ignore();

    cout << "Enter the Name: ";
    getline(cin, client.name);

    cout << "Enter the Phone: ";
    cin >> client.phone;

    cout << "Enter the Account Balance: ";
    cin >> client.accountBalance;
}

string convertRecordToLine(ClientData client, string delim)
{
    string result = "";

    result += client.accountNum + delim;
    result += client.pinCode + delim;
    result += client.name + delim;
    result += client.phone + delim;
    result += to_string(client.accountBalance);

    return result;
}

int main()
{
    ClientData client1;

    cout << "\nPlease enter your data: \n";
    cout << "----------------------\n";
    readClientData(client1);

    cout << "\nClient Data: \n";
    cout << "----------- \n";
    cout << convertRecordToLine(client1, "#//#") << "\n\n";

    return 0;
}
