#include <iostream>
#include <string>
using namespace std;

string removePunctuations(string s)
{
    string result = "";

    for (char ch : s)
    {
        if (!ispunct(ch))
            result += ch;
    }

    return result;
}

int main()
{
    string s = "Welcome to Egypt, Egypt is a nice country; It's amazing.";

    cout << "\nOriginal String: \n";
    cout << "---------------\n";
    cout << s << endl;

    cout << "\nString after removing punctuations: \n";
    cout << "---------------------------------- \n";
    cout << removePunctuations(s) << "\n\n";

    return 0;
}
