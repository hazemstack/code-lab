#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const string clientsFile = "clients.txt";

struct ClientsData
{
    string accountNum;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
};

ClientsData readClientData()
{
    ClientsData client;

    cout << "Enter the account number: ";
    cin >> client.accountNum;

    cout << "Enter the pin code: ";
    cin >> client.pinCode;

    cin.ignore();

    cout << "Enter the name: ";
    getline(cin, client.name);

    cout << "Enter the phone: ";
    cin >> client.phone;

    cout << "Enter the account balance: ";
    cin >> client.accountBalance;

    return client;
}

string convertRecordToLine(ClientsData client, string delim = "#//#")
{
    string dataLine;

    dataLine += client.accountNum + delim;
    dataLine += client.pinCode + delim;
    dataLine += client.name + delim;
    dataLine += client.phone + delim;
    dataLine += to_string(client.accountBalance);

    return dataLine;
}

void addDataLineToFile(string fileName, string dataLine)
{
    fstream myFile;
    myFile.open(fileName, ios::out | ios::app);

    if (myFile.is_open())
    {
        myFile << dataLine << endl;

        myFile.close();
    }
}

void addNewClient()
{
    ClientsData client;
    client = readClientData();

    addDataLineToFile(clientsFile, convertRecordToLine(client));
}

void addClients()
{
    char addMore = 'y';

    do
    {
        system("cls");
        cout << "\nAdding a new client:\n";
        cout << "-------------------\n";
        addNewClient();

        cout << "\nThe client added successfully, Do you want to add more clients ( y, n )? ";
        cin >> addMore;

    } while (addMore == 'y' || addMore == 'Y');
}

int main()
{
    addClients();

    return 0;
}