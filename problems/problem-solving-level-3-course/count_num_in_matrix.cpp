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

int countNumInMatrix(int arr[3][3], int num, int rows, int cols)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == num)
                count++;
        }
    }
    return count;
}

int main()
{
    int arr[3][3] = {{9, 6, 0}, {0, 9, 3}, {4, 0, 9}};
    int elem;

    cout << "The matrix:\n";
    cout << "----------\n";
    printMatrix(arr, 3, 3);

    cout << "Enter the number to count in the matrix: ";
    cin >> elem;

    cout << "\nThe number " << elem << " appeared in the matrix ";
    cout << countNumInMatrix(arr, elem, 3, 3) << " times.\n\n";
    
    return 0;
}