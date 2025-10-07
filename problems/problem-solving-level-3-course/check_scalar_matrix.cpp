#include <iostream>
#include <iomanip>
using namespace std;

void printMatrix(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(2) << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isScalarMatrix(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i != rows - 1 || j != cols - 1)
            {
                if (i == j && arr[i][j] != arr[i + 1][j + 1])
                return false;
            }
            
            if (i != j && arr[i][j] != 0)
                return false;
        }
    }

    return true;
}

int main()
{
    int arr[3][3] = {{9, 0, 0}, {0, 9, 0}, {0, 0, 9}};

    cout << "The matrix:\n";
    cout << "----------\n";
    printMatrix(arr, 3, 3);

    if (isScalarMatrix(arr, 3, 3))
        cout << "It is a scalar matrix.\n\n";
    else
        cout << "It is not a scalar matrix.\n\n";
    
    return 0;
}