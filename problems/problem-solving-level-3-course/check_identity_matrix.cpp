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

bool isIdentityMatrix(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j && arr[i][j] != 1 || i != j && arr[i][j] != 0)
                return false;
        }
    }
    return true;
}

int main()
{
    int arr[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    cout << "The matrix:\n";
    cout << "----------\n";
    printMatrix(arr, 3, 3);

    if (isIdentityMatrix(arr, 3, 3))
    {
        cout << "It is an identity matrix.\n\n";
    }
    else 
    {
        cout << "It is not an identity matrix.\n\n";
    }

    return 0;
}