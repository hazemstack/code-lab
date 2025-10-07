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

int main()
{
    srand(time(NULL));
    int randomArr[3][3];

    fillMatrixWithRandomNumbers(randomArr, 3, 3);

    cout << "\nRandom Matrix:\n";
    cout << "-------------\n";
    printMatrix(randomArr, 3, 3);

    cout << "The sum of the matrix = ";
    cout << sumOfMatrix(randomArr, 3 , 3) << "\n\n";

    return 0;
}