#include <iostream>
#include <string>
#include <vector>
using namespace std;

string joinString(vector<string> list, string delim)
{
    string result = "";

    for (string elem : list)
    {
        result += elem + delim;
    }

    return result.substr(0, result.find_last_not_of(delim) + 1);
}

string joinString(string arr[], int arrLength, string delim)
{
    string result = "";

    for (int i = 0; i < arrLength; i++)
    {
        result += arr[i] + delim;
    }

    return result.substr(0, result.find_last_not_of(delim) + 1);
}

int main()
{
    vector<string> elements = {"Hazem", "El-Saeed", "Mahgoub"};
    string arr[] = {"Hazem", "El-Saeed", "Mahgoub"};

    cout << "\nVector after join: \n";
    cout << "-----------------\n";
    cout << joinString(elements, "***") << endl;
    
    cout << "\nArray after join: \n";
    cout << "-----------------\n";
    cout << joinString(arr, 3, "***") << "\n\n";

    return 0;
}
