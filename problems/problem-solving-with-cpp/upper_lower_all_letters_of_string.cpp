#include <iostream>
#include <cctype>
using namespace std;

string readString()
{
    string str;
    cout << "\nEnter your string: ";
    getline(cin, str);

    return str;
}

string toUpperCase(string str)
{
    string result = "";

    cout << "\nString after conversion to upper case: \n";
    cout << "------------------------------------- \n";
    for (char ch : str)
    {
        if (islower(ch))
            result += toupper(ch);
        else
            result += ch;
    }

    return result;
}

string toLowerCase(string str)
{
    string result = "";

    cout << "\nString after conversion to lower case: \n";
    cout << "------------------------------------- \n";
    for (char ch : str)
    {
        if (isupper(ch))
            result += tolower(ch);
        else
            result += ch;
    }

    return result;
}

int main()
{
    string str = readString();
    cout << toUpperCase(str) << endl;
    cout << toLowerCase(str) << "\n\n";

    return 0;
}