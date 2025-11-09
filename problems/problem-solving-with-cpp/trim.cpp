#include <iostream>
#include <string>
using namespace std;

string trim(string str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == string::npos)
        return "";

    size_t end = str.find_last_not_of(" \t\n\r");

    return str.substr(start, end - start + 1);
}

string trim_left(string str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == string::npos)
        return "";

    return str.substr(start);
}

string trim_right(string str)
{
    size_t end = str.find_last_not_of(" \t\n\r");
    if (end == string::npos)
        return "";

    return str.substr(0, end + 1);
}

int main()
{
    string s = "    Hello World    ";

    cout << endl;
    cout << "[" << trim(s) << "]" << endl;

    cout << "[" << trim_left(s) << "]"<< endl;

    cout << "[" << trim_right(s) << "]" << "\n\n";
    
    return 0;
}
