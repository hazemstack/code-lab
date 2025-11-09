#include <iostream>
#include <iomanip>
using namespace std;

void printMatrix(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isNumberInMatrix(int arr[3][3], int num, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == num)
                return true;
        }
    }
    return false;
}

void printIntersectedNumbers(int first_arr[3][3], int second_arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (isNumberInMatrix(second_arr, first_arr[i][j], rows, cols))
            {
                cout << first_arr[i][j] << " ";
            }
        }
    }
    cout << endl;
}

int main()
{
    int first_arr[3][3] = { {77, 5, 12}, {22, 20, 1}, {1, 0, 9} };
    int second_arr[3][3] = { {5, 80, 90}, {22, 77, 1}, {10, 8, 33} };

    cout << "Matrix 1:\n";
    cout << "--------\n";
    printMatrix(first_arr, 3, 3);

    cout << "Matrix 2:\n";
    cout << "--------\n";
    printMatrix(second_arr, 3, 3);

    cout << "The Intersected Numbers: ";
    printIntersectedNumbers(first_arr, second_arr, 3, 3);

    return 0;
}