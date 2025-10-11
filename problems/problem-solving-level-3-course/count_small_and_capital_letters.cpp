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

int countCapitalLetters(string str)
{
    int count = 0;

    for (char ch : str)
    {
        if (isupper(ch))
            count++;
    }

    return count;
}

int countSmallLetters(string str)
{
    int count = 0;

    for (char ch : str)
    {
        if (islower(ch))
            count++;
    }

    return count;
}

int main()
{
    string input = readString();

    cout << "\nString Length = " << input.size() << endl;
    cout << "Capital Letters Count = " << countCapitalLetters(input) << endl;
    cout << "Small Letters Count = " << countSmallLetters(input) << "\n\n";

    return 0;
}