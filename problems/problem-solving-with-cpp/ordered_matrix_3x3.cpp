#include <iostream>
#include <iomanip>
using namespace std;

void fillMatrixWithOrderedNumbers(int matrix[3][3], int rows, int cols)
{
    int start = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = start;
            start++;
        }
    }
}

void printMatrix(int matrix[3][3], int rows, int cols)
{
    cout << "3x3 Ordered Matrix:\n";
    cout << "------------------\n";
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

int main()
{
    int matrix1[3][3];

    fillMatrixWithOrderedNumbers(matrix1, 3, 3);
    printMatrix(matrix1, 3, 3);

    return 0;
}