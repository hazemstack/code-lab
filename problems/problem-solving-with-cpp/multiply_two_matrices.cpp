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
            arr[i][j] = generateRandomNumber(1, 10);
        }
    }
}

void printMatrix(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(2) << setfill('0') << arr[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

void multiplyTwoMatrices(int arr1[3][3], int arr2[3][3], int results[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            results[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}

int main()
{
    srand(time(NULL));

    int randArr1[3][3];
    int randArr2[3][3];
    int results[3][3];

    fillMatrixWithRandomNumbers(randArr1, 3, 3);
    cout << "Random Matrix 1:\n";
    cout << "---------------\n";
    printMatrix(randArr1, 3, 3);

    fillMatrixWithRandomNumbers(randArr2, 3, 3);
    cout << "Random Matrix 2:\n";
    cout << "---------------\n";
    printMatrix(randArr2, 3, 3);

    multiplyTwoMatrices(randArr1, randArr2, results, 3, 3);
    cout << "Results:\n";
    cout << "-------\n";
    printMatrix(results, 3, 3);

    return 0;
}