#include <iostream>
#include <iomanip>
using namespace std;

// 3*3 Random Matrix

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

int main()
{
    srand(time(NULL));

    int arr1[3][3];

    fillMatrixWithRandomNumbers(arr1, 3, 3);
    cout << "3*3 Random Matrix:\n";
    cout << "-----------------\n";
    printMatrix(arr1, 3, 3);

    return 0;
}