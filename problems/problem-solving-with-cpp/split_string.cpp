#include <iostream>
#include <string>
#include <vector>
using namespace std;

string readString()
{
    string s = "";
    cout << "\nEnter your string: ";
    getline(cin, s);

    return s;
}

vector<string> splitString(string s, string delim)
{
    vector<string> result;
    string word = "";
    int pos = 0;

    while ((pos = s.find(delim)) != string::npos)
    {
        word = s.substr(0, pos);
        result.push_back(word);

        s.erase(0, pos + delim.length());
    }

    result.push_back(s);
    return result;
}

int main()
{
    string input = readString();
    vector<string> words = splitString(input, " ");

    cout << "\nTokens = " << words.size() << endl;

    for (string &elem : words)
    {
        cout << elem << endl;
    }
    cout << endl;
       
    return 0;
}