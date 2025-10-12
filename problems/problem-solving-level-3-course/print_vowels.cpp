#include <iostream>
#include <set>
using namespace std;

string readString()
{
    string str;
    cout << "\nEnter your string: ";
    getline(cin, str);

    return str;
}

bool isVowel(char ch)
{
    set<char> vowels = {'a', 'i', 'u', 'e', 'o', 'A','I', 'U', 'E', 'O'};

    return vowels.count(ch);
}

void printVowels(string str)
{
    cout << "\nVowels in the string are: ";
    for (char elem : str)
    {
        if (isVowel(elem))
        {
            cout << elem << "  ";
        }
    }
    cout << endl;
}

int main()
{
    string input = readString();

    printVowels(input);
    cout << endl;
    
    return 0;
}