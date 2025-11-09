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

string capitalizeWords(string str)
{
    string result = "";
    bool isFirstLetter = true;

    cout << "\nString after conversion: \n";
    cout << "------------------------\n";

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ' && isFirstLetter)
            result += toupper(str[i]);
        else
            result += str[i];

        isFirstLetter = (str[i] == ' ');
    }

    return result;
}

int main()
{
    cout << capitalizeWords(readString()) << "\n\n";

    return 0;
}