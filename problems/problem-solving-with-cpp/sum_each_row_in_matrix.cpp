#include <iostream>
#include <iomanip>
using namespace std;

int generateRandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void fillMatrixWithRandomNumbers(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = generateRandomNumber(1, 100);
        }
    }
}

void printMatrix(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int rowSum(int arr[3][3], int rowNum, int cols)
{
    int sum = 0;
    for (int i = 0; i < cols; i++)
    {
        sum += arr[rowNum][i];
    }

    return sum;
}

void printRowSums(int arr[3][3], int cols)
{
    cout << "The sum of each row in the matrix:\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < cols; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << rowSum(arr, i, cols) << endl;
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));

    int arr1[3][3];

    fillMatrixWithRandomNumbers(arr1, 3, 3);
    cout << "3*3 Random Matrix:\n";
    cout << "-----------------\n";
    printMatrix(arr1, 3, 3);

    printRowSums(arr1, 3);

    return 0;
}