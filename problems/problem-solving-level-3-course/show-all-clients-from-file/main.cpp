#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

/*
                            
                                Clients List
                                ============
------------------------------------------------------------------------------------
| Account Number  | Pin Code  | Client Name      | Phone        | Account Balance  |
------------------------------------------------------------------------------------
| A100            | 1234      | Hazem El-Saeed   | 01098765432  | 4000             |
| A101            | 1357      | Omar Ali         | 01023456789  | 3000             |
| A102            | 1479      | Youssef Ahmed    | 01012345678  | 2000             | 
------------------------------------------------------------------------------------

*/

const string clientsFile = "clients.txt";

struct ClientData
{
    string accountNum;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
};

vector<string> splitString(string s, string delim)
{
    vector<string> result;
    int pos = 0;
    string word;

    while ((pos = s.find(delim)) != string::npos)
    {
        word = s.substr(0, pos);
        result.push_back(word);

        s.erase(0, pos + delim.length());
        word.clear();
    }

    result.push_back(s);
    return result;
}

ClientData convertLineToRecord(string line, string delim = "#//#")
{
    ClientData client;
    vector<string> fields = splitString(line, delim);

    client.accountNum = fields[0];
    client.pinCode = fields[1];
    client.name = fields[2];
    client.phone = fields[3];
    client.accountBalance = stod(fields[4]);

    return client;
}

vector<ClientData> loadClientDataFromFile(string fileName)
{
    vector<ClientData> clients;
    fstream myFile;
    myFile.open(fileName, ios::in); // read mode

    if (myFile.is_open())
    {
        string line;
        ClientData client;

        while (getline(myFile, line))
        {
            client = convertLineToRecord(line);
            clients.push_back(client);
        }

        myFile.close();
    }

    return clients;
}

void printClientRecord(ClientData client)
{
    cout << "| " << left << setw(16) << client.accountNum;
    cout << "| " << left << setw(10) << client.pinCode;
    cout << "| " << left << setw(18) << client.name;
    cout << "| " << left << setw(13) << client.phone;
    cout << "| " << left << setw(10) << client.accountBalance << "       |";
}

void printAllClientsData(vector<ClientData> clients)
{
    cout << "\n\t\t\t\tClients List\n";
    cout << "\t\t\t\t============\n";
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "| " << left << setw(16) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(18) << "Client Name";
    cout << "| " << left << setw(13) << "Phone";
    cout << "| " << left << setw(10) << "Account Balance" << "  |";
    cout << "\n-------------------------------------------------------------------------------------\n";

    for (ClientData client : clients)
    {
        printClientRecord(client);
        cout << endl;
    }

    cout << "-------------------------------------------------------------------------------------\n\n";
}

int main()
{
    vector<ClientData> clients = loadClientDataFromFile(clientsFile);

    system("cls");
    printAllClientsData(clients);

    return 0;
}