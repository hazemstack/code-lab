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

char invertLetterCase(char ch)
{
    cout << "\nCharacter after inverting case: ";

    if (isupper(ch))
        return tolower(ch);
    else
        return toupper(ch);
}

int main()
{
    cout << invertLetterCase(readChar()) << "\n\n";

    return 0;
}