#include <iostream>
#include <iomanip>
using namespace std;

void printMatrix(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << left << setw(2) << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isPalindromeMatrix(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols / 2; j++)
        {
            if (arr[i][j] != arr[i][cols - 1 - j]) 
                return false;
        }
    }
    return true;
}

int main()
{
    int arr[3][3] = {{1, 2, 1},{5, 5, 5},{7, 3, 7}};

    cout << "Matrix:\n";
    cout << "-------\n";
    printMatrix(arr, 3, 3);

    if (isPalindromeMatrix(arr, 3, 3))
        cout << "It is a palindrome matrix.\n\n";
    else
        cout << "It is not a palindrome matrix.\n\n";

    return 0;
}
