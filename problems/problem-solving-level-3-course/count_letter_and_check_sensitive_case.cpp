#include <iostream>
using namespace std;

string readString()
{
    string str;
    cout << "\nEnter your string: ";
    getline(cin, str);

    return str;
}

char readChar()
{
    char ch;
    cout << "Enter your character: ";
    cin >> ch;

    return ch;
}

char invertLetterCase(char ch)
{
    return isupper(ch) ? tolower(ch) : toupper(ch);
}

int countChar(char ch, string str, bool isSensitiveCase = true)
{
    int count = 0;
    
    if (isSensitiveCase)
    {
        for (char elem : str)
        {
            if (elem == ch)
                count++;
        }
    }
    else 
    {
        for (char elem : str)
        {
            if (tolower(elem) == tolower(ch))
                count++;
        }
    }

    return count;
}

int main()
{
    string str = readString();
    char ch = readChar();

    cout << "\nLetter '" << ch << "' Count = " << countChar(ch, str) << endl;

    cout << "Letter '" << ch << "' or '" << invertLetterCase(ch) << "' Count = ";
    cout << countChar(invertLetterCase(ch), str, false) << "\n\n";
    
    return 0;
}