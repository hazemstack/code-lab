#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>
using namespace std;

// Deleting a Client Record from a File

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
    cout << "\nClient Data:\n";
    cout << "-----------\n";

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

void deleteClientRecord(string accountNum)
{
    char confirmDelete;

    ifstream originalFile(clientsFile);
    ofstream tempFile("temp.txt");

    cout << "\nAre you sure you want to delete this client ( Y, N )? ";
    cin >> confirmDelete;

    if (confirmDelete == 'Y' || confirmDelete == 'y')
    {
        if (originalFile.is_open())
        {
            string line;
            while (getline(originalFile, line))
            {
                ClientRecord record = convertLineToRecord(line);

                if (accountNum != record.accountNum)
                {
                    tempFile << convertRecordToLine(record) << endl;
                }
            }

            originalFile.close();
            tempFile.close();
        }

        remove(clientsFile.c_str());
        rename("temp.txt", "clients.txt");

        cout << "\nThe client has been successfully deleted.\n";
    }
    else
    {
        cout << "\nDeletion has been canceled.\n";
    }
}

int main()
{
    string accountNum = readAccountNum();
    ClientRecord client;

    if (findClientInFile(accountNum, client, clientsFile))
    {
        printClientRecord(client);
        deleteClientRecord(accountNum);
    }
    else
    {
        cout << "\nThe account number does not exist.\n";
    }

    cout << endl;

    return 0;
}