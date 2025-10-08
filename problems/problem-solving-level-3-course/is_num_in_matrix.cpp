#include <iostream>
#include <iomanip>
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

bool isNumInMatrix(int arr[3][3], int num, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == num)
                return true;
        }
    }
    return false;
}

int main()
{
    int arr[3][3] = { {0, 1, 0}, {0, 2, 5}, {4, 0, 0} };
    int num;

    cout << "\nThe Matrix:\n";
    cout << "----------\n";
    printMatrix(arr, 3, 3);

    cout << "Enter the number to look for in matrix: ";
    cin >> num;

    if (isNumInMatrix(arr, num, 3, 3))
    {
        cout << "The number is in the matrix.\n";
    }
    else
    {
        cout << "The number is not in the matrix.\n";
    }

    return 0;
}