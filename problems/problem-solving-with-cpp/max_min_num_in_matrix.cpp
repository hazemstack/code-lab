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

int maxNumInMatrix(int arr[3][3], int rows, int cols)
{
    int max = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }
    return max;
}

int minNumInMatrix(int arr[3][3], int rows, int cols)
{
    int min = INT_MAX;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] < min)
                min = arr[i][j];
        }
    }
    return min;
}

int main()
{
    int arr[3][3] = {{1, 9, 99},{3, 2, 77},{9, 3, 5}};

    cout << "Matrix:\n";
    cout << "-------\n";
    printMatrix(arr, 3, 3);

    cout << "The maximum number in the matrix = ";
    cout << maxNumInMatrix(arr, 3, 3) << endl;

    cout << "\nThe minimum number in the matrix = ";
    cout << minNumInMatrix(arr, 3, 3) << "\n\n";

    return 0;
}
