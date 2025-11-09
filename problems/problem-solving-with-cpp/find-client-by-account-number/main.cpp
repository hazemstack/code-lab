#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string clientsFile = "clients.txt";

struct ClientData
{
    string accountNum;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
};

ClientData convertLineToRecord(string line, string delim = "#//#")
{
    ClientData client;
    int pos = 0;
    string field = "";
    int fieldCount = 0;

    while ((pos = line.find(delim)) != string::npos)
    {
        field = line.substr(0, pos);

        switch (fieldCount)
        {
            case 0:
                client.accountNum = field;
                break;

            case 1:
                client.pinCode = field;
                break;

            case 2:
                client.name = field;
                break;

            case 3:
                client.phone = field;
                break;
            
        };

        line.erase(0, pos + delim.length());
        fieldCount++;
    }

    client.accountBalance = stod(line);
    return client;
}

vector<ClientData> loadAllClientsDataFromFile(string fileName)
{
    vector<ClientData> clients;
    fstream myFile;

    myFile.open(fileName, ios::in);

    if (myFile.is_open())
    {
        string line;

        while (getline(myFile, line))
        {
            clients.push_back(convertLineToRecord(line));
        }

        myFile.close();
    }
    
    return clients;
}

void printClientData(ClientData client)
{
    cout << "\nClient Data:\n";
    cout << "-----------\n";

    cout << "Account Number : " << client.accountNum << endl;
    cout << "Pin Code       : " << client.pinCode << endl;
    cout << "Name           : " << client.name << endl;
    cout << "phone          : " << client.phone << endl;
    cout << "Account Balance: " << client.accountBalance << endl;
}

bool findClientByAccountNumber(string accountNum, ClientData &client)
{
    vector<ClientData> clients = loadAllClientsDataFromFile(clientsFile);

    for (ClientData &c : clients)
    {
        if (c.accountNum == accountNum)
        {
            client = c;
            return true;
        }
    }

    return false;
}

string readAccountNumber()
{
    string accountNum;
    cout << "\nEnter the account number: ";
    cin >> accountNum;

    return accountNum;
}

int main()
{
    system("cls");

    string accountNum = readAccountNumber();
    ClientData client;

    if (findClientByAccountNumber(accountNum, client))
        printClientData(client);
    else
        cout << "\nThe client with account number " << accountNum << " is not found!\n";

    cout << endl;

    return 0;
}