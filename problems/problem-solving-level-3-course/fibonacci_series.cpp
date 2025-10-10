#include <iostream>
#include <iomanip>
using namespace std;

// Fibonacci Series Of 10 Terms: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34

void fibonacciSeries(int n)
{
    int first = 0;
    int second = 1;

    cout << first << " " << second << " "; 
    for (int i = 0; i < n - 2; i++)
    {
        int next = first + second;
        cout << next << " ";
        first = second;
        second = next;
    }
}

int main()
{
    fibonacciSeries(10);

    return 0;
}
