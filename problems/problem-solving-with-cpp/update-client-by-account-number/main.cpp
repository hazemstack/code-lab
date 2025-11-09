#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Update client record in a file.

const string clientsFile = "clients.txt";

struct ClientRecord
{
    string accountNum;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
};

string readAccountNum()
{
    string accountNum;

    cout << "\nEnter the account number: ";
    cin >> accountNum;

    return accountNum;
}

void printClientRecord(ClientRecord client)
{
    cout << "Account Number : " << client.accountNum << endl;
    cout << "Pin Code       : " << client.pinCode << endl;
    cout << "Name           : " << client.name << endl;
    cout << "Phone          : " << client.phone << endl;
    cout << "Account Balance: " << client.accountBalance << endl;
}

string convertRecordToLine(ClientRecord client, string delim = "#//#")
{
    return client.accountNum + delim + client.pinCode + delim + client.name + delim + client.phone + delim + to_string(client.accountBalance);
}

ClientRecord convertLineToRecord(string line, string delim = "#//#")
{
    ClientRecord client;
    int pos = 0;
    string token = "";
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

    if (!line.empty())
    {
        client.accountBalance = stod(line);
    }

    return client;
}

vector<ClientRecord> loadAllClientsFromFile(string fileName)
{
    ifstream file(fileName);
    vector<ClientRecord> clients;

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            ClientRecord record = convertLineToRecord(line);
            clients.push_back(record);
        }

        file.close();
    }

    return clients;
}

bool findClientInFile(string accountNum, ClientRecord &client, string fileName)
{
    vector<ClientRecord> clients = loadAllClientsFromFile(fileName);

    for (ClientRecord &c : clients)
    {
        if (c.accountNum == accountNum)
        {
            client = c;
            return true;
        }
    }

    return false;
}

void updateClientRecord(string accountNum, string fileName)
{
    vector<ClientRecord> clients = loadAllClientsFromFile(fileName);
    char confirmUpdate;

    cout << "\nAre you sure you want to update this client record ( Y, N )? ";
    cin >> confirmUpdate;

    if (confirmUpdate == 'y' || confirmUpdate == 'Y')
    {
        for (ClientRecord &c : clients)
        {
            if (c.accountNum == accountNum)
            {
                cout << "\nEnter the pin code: ";
                cin >> c.pinCode;

                cout << "Enter the name: ";
                cin.ignore();
                getline(cin, c.name);

                cout << "Enter the phone: ";
                cin >> c.phone;

                cout << "Enter the account balance: ";
                cin >> c.accountBalance;
            }
        }

        ofstream file(fileName);

        if (file.is_open())
        {
            for (ClientRecord &c : clients)
            {
                file << convertRecordToLine(c) << endl;
            }

            file.close();
        }

        cout << "\nThe client record has been successfully updated.\n";
    }
    else
    {
        cout << "\nThe update has been canceled!\n";
    }
}

int main()
{
    string accountNum = readAccountNum();
    ClientRecord client;

    if (findClientInFile(accountNum, client, clientsFile))
    {
        cout << "\nClient Record:\n";
        cout << "-------------\n";
        printClientRecord(client);

        updateClientRecord(accountNum, clientsFile);

        findClientInFile(accountNum, client, clientsFile);

        cout << "\nClient Record After Update:\n";
        cout << "--------------------------\n";
        printClientRecord(client);
    }
    else
    {
        cout << "\nThe account number doesn't exist!\n";
    }

    cout << endl;

    return 0;
}