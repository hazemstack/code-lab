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

string decapitalizeWords(string str)
{
    string result = "";
    bool isFirstLetter = true;

    cout << "\nString after conversion: \n";
    cout << "------------------------\n";

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ' && isFirstLetter)
            result += tolower(str[i]);
        else
            result += str[i];

        isFirstLetter = (str[i] == ' ');
    }

    return result;
}

int main()
{
    cout << decapitalizeWords(readString()) << "\n\n";

    return 0;
}