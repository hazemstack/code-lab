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

int countWords(string s)
{
    int count = 0;
    string word = "";

    for (char ch : s)
    {
        if (ch != ' ')
        {
            word += ch;
        }
        else
        {
            count++;
            word.clear();
        }
    }

    count++;
    return count;
}

int main()
{
    string input = readString();

    cout << "\nThe number of the words in this string = ";
    cout << countWords(input) << "\n\n";
       
    return 0;
}