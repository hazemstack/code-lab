#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string replaceString(string s, string old_word, string new_word)
{
    int pos = s.find(old_word);

    while (pos != string::npos)
    {
        s = s.replace(pos, old_word.length(), new_word);
        pos = s.find(old_word);
    }

    return s;
}

int main()
{
    string s = "Welcome to Egypt, Egypt is a nice country.";

    cout << "\nOriginal String: \n";
    cout << s << endl;

    cout << "\nString after replace: \n";
    cout << replaceString(s, "Egypt", "USA") << "\n\n";

    return 0;
}
