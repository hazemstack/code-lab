#include <iostream>
using namespace std;

// Fibonacci Series Of 10 Terms: 0 1 1 2 3 5 8 13 21 34

void fibonacciSeries(int n, int first, int second) 
{
    if (n == 0) return; // Base Case

    cout << first << " ";
    fibonacciSeries(n - 1, second, first + second); // Recursive Call
}

int main()
{
    fibonacciSeries(10, 0, 1);
    
    return 0;
}
