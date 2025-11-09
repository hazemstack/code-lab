#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string readString()
{
    string s;
    cout << "\nEnter your string: ";
    getline(cin, s);

    return s;
}

string reverseWords(string s)
{
    string result = "";
    string temp = "";

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            temp += s[i];
        }
        else
        {
            reverse(temp.begin(), temp.end());
            result += temp + " ";
            temp.clear();
        }
    }

    reverse(temp.begin(), temp.end());
    result += temp;
    return result;
}

int main()
{
    string input = readString();

    cout << "\nThe string after reversing words: \n";
    cout << "--------------------------------\n";
    cout << reverseWords(input) << "\n\n";
    
    return 0;
}
