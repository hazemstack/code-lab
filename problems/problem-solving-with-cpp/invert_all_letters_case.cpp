#include <iostream>
#include <cctype>
using namespace std;

char readChar()
{
    char ch;
    cout << "\nEnter your character: ";
    cin >> ch;

    return ch;
}

string readString()
{
    string str;
    cout << "\nEnter your string: ";
    getline(cin, str);

    return str;
}

char invertLetterCase(char ch)
{
    if (isupper(ch))
        return tolower(ch);
    else
        return toupper(ch);
}

string invertALLLettersCase(string str)
{
    string result = "";

    for (char ch : str)
    {
        result += invertLetterCase(ch);
    }

    return result;
}

int main()
{
    string input = readString();

    cout << "\nString after inverting all letters case:\n";
    cout << "---------------------------------------\n";
    cout << invertALLLettersCase(input) << "\n\n";

    return 0;
}