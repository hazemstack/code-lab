#include <iostream>
#include <set>
using namespace std;

char readChar()
{
    char ch;
    cout << "\nEnter your character: ";
    cin >> ch;

    return ch;
}

bool isVowel(char ch)
{
    set<char> vowels = {'a', 'u', 'o', 'e', 'i', 'A', 'U', 'O', 'E', 'I'};

    return vowels.count(ch);
}

int main()
{
    char input = readChar();

    if (isVowel(input))
        cout << "\nLetter '" << input << "' is a vowel.\n\n";
    else
        cout << "\nLetter '" << input << "' is not a vowel.\n\n";
    
    return 0;
}