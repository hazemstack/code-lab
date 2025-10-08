#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void printMatrix(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(2) << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isParseMatrix(int arr[3][3], int rows, int cols)
{
    int zeros_count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 0)
                zeros_count++;
        }
    }
    return zeros_count > ceil( rows * cols / 2 );
}

int main()
{
    int arr[3][3] = {{0, 1, 0}, {0, 2, 5}, {4, 0, 0}};

    cout << "\nThe Matrix:\n";
    cout << "----------\n";
    printMatrix(arr, 3, 3);

    if (isParseMatrix(arr, 3, 3))
    {
        cout << "It is a parce matrix.\n\n";
    }
    else
    {
        cout << "It isn't a parce matrix.\n\n";
    }

    return 0;
}