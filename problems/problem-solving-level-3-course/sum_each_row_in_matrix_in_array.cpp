#include <iostream>
#include <iomanip>
using namespace std;

int generateRandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void fillMatrixWithRandomNumbers(int matrix[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = generateRandomNumber(1, 100);
        }
    }
}

void printMatrix(int matrix[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void fillArrayWithRowSums(int matrix[3][3], int arr[3], int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
            arr[i] = sum;
        }
        sum = 0;
    }
}

void printArray(int arr[3], int rows)
{
    cout << "The sum of each row in the matrix:\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << arr[i] << endl;
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));

    int matrix1[3][3];
    int arr1[3];

    fillMatrixWithRandomNumbers(matrix1, 3, 3);
    cout << "3*3 Random Matrix:\n";
    cout << "-----------------\n";
    printMatrix(matrix1, 3, 3);

    fillArrayWithRowSums(matrix1, arr1, 3, 3);
    printArray(arr1, 3);

    return 0;
}