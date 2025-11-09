#include <iostream>
#include <iomanip>
using namespace std;

void fillMatrixWithOrderedNumbers(int arr[3][3], int rows, int cols)
{
    int start = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = start;
            start++;
        }
    }
}

void transposeMatrix(int arr[3][3], int transposedArr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transposedArr[i][j] = arr[j][i];
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

int main()
{
    int orderedArr[3][3];
    int transposedArr[3][3];

    fillMatrixWithOrderedNumbers(orderedArr, 3, 3);
    cout << "3x3 Ordered Matrix:\n";
    cout << "------------------\n";
    printMatrix(orderedArr, 3, 3);

    transposeMatrix(orderedArr, transposedArr, 3, 3);
    cout << "3x3 Transposed Matrix:\n";
    cout << "---------------------\n";
    printMatrix(transposedArr, 3, 3);

    return 0;
}