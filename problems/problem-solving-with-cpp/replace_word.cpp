#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string replaceString(string s, string old_word, string new_word)
{
    istringstream iss(s);
    string word, result = "";

    while (iss >> word) 
    {
        char lastChar = word.back(); 
        bool hasPunc = ispunct(lastChar); 

        string pure_word = hasPunc ? word.substr(0, word.length() - 1) : word; 

        if (pure_word == old_word)
            pure_word = new_word;

        result += pure_word; 

        if (hasPunc)
            result += lastChar;

        result += " ";
    }

    if (!result.empty() && result.back() == ' ')
        result.pop_back();

    return result;
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
