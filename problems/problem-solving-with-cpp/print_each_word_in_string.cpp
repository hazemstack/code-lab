#include <iostream>
#include <string>
using namespace std;

string readString()
{
    string str;
    cout << "\nEnter your string: ";
    getline(cin, str);

    return str;
}

void printEachWordInString(string s)
{
    string word = "";
    
    cout << "\nThe words in this string:\n";
    cout << "------------------------\n";
    for (char ch : s)
    {
        if (ch != ' ')
        {
            word += ch;
        }
        else
        { 
            cout << word << endl;
            word.clear();
        }
    }
    
    cout << word << endl;
}

int main()
{
    string input = readString();

    printEachWordInString(input);
    cout << endl;
       
    return 0;
}