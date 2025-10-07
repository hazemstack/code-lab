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

void printMiddleRow(int arr[3][3], int rows, int cols)
{
    int middleRow = rows / 2;

    cout << "The middle row:\n";
    cout << "--------------\n";
    for (int i = 0; i < cols; i++)
    {
        cout << setw(2) << setfill('0') << arr[middleRow][i] << "   ";
    }
    cout << endl;
}

void printMiddleCol(int arr[3][3], int rows, int cols)
{
    int middleCol = cols / 2;

    cout << "The middle column:\n";
    cout << "-----------------\n";
    for (int i = 0; i < rows; i++)
    {
        cout << setw(2) << setfill('0') << arr[i][middleCol] << "   ";
    }
    cout << endl;
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

int main()
{
    srand(time(NULL));
    int randomArr[3][3];

    fillMatrixWithRandomNumbers(randomArr, 3, 3);

    cout << "Random Matrix:\n";
    cout << "------------\n";
    printMatrix(randomArr, 3, 3);

    printMiddleRow(randomArr, 3, 3);
    cout << endl;

    printMiddleCol(randomArr, 3 ,3);
    cout << endl;

    return 0;
}