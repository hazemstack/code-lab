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

int countChar(char ch, string str)
{
    int count = 0;
    for (char elem : str)
    {
        if (elem == ch)
            count++;
    }

    return count;
}

int main()
{
    string str = readString();
    char ch = readChar();

    cout << "\nLetter '" << ch << "' Count = " <<countChar(ch, str) << "\n\n";
    
    return 0;
}