#include <iostream>
using namespace std;

string readString()
{
    string str;
    cout << "Enter your string: ";
    getline(cin, str);

    return str;
}

void printFirstLetters(string str)
{
    cout << "\nFirst letters of this string:\n";
    cout << "----------------------------\n";
    cout << str[0] << endl;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == ' ')
            cout << str[i + 1] << endl;
    }
    cout << endl;
}

int main()
{
    printFirstLetters(readString());

    return 0;
}