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

int sumOfMatrix(int arr[3][3], int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
    }
    
    return sum;
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

bool areMatricesIsEqual(int firstArr[3][3], int secondArr[3][3], int rows, int cols)
{
    if (sumOfMatrix(firstArr, rows, cols) == sumOfMatrix(secondArr, rows, cols))
        return true;
    else
        return false;
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

    if (areMatricesIsEqual(firstArr, secondArr, 3, 3))
    {
        cout << "The two matrices are equal." << "\n\n";
    }
    else 
    {
        cout << "The two matrices are not equal.\n\n";
    }

    return 0;
}