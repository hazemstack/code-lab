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
            cout << setw(2) << setfill('0') << arr[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;
}

bool areTypicalMatrices(int firstArr[3][3], int secondArr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (firstArr[i][j] != secondArr[i][j])
                return false;
        }
    }
    return true;
}

int main()
{
    srand(time(NULL));

    int firstArr[3][3];
    int secondArr[3][3];

    fillMatrixWithRandomNumbers(firstArr, 3, 3);
    fillMatrixWithRandomNumbers(secondArr, 3, 3);

    cout << "\nRandom Matrix 1:\n";
    cout << "---------------\n";
    printMatrix(firstArr, 3, 3);

    cout << "\nRandom Matrix 2:\n";
    cout << "---------------\n";
    printMatrix(secondArr, 3, 3);

    if (areTypicalMatrices(firstArr, secondArr, 3, 3))
    {
        cout << "The two matrices are typical.\n\n";
    }
    else
    {
        cout << "The two matrices are not typical.\n\n";
    }

    return 0;
}