// C++ program to check whether a given
// matrix is magic matrix or not
#include <iostream>
#include <iomanip>

using namespace std;

// Function to check the array for elements in
// given range
bool check_elements(int **arr, int n)
{
    int range = n * n - 1;

    // Traversing the array
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            // If an element is in range
            if (abs(arr[i][j]) >= 0 && abs(arr[i][j]) <= range)
            {

                // Negating at index ‘element/N, element%N’
                int k = abs(arr[i][j]) / n;
                int l = abs(arr[i][j]) % n;
                if (arr[k][l] > 0)
                {
                    arr[k][l] = arr[k][l] * -1;
                }
            }
        }
    }

    

    // Checking whether elements in range 0-range
    // are negative
    int count = 0;
    for (int i = 0; i <= range && i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            // Element from range is missing from array
            if (arr[i][j] > 0)
                return false;
            else
                count++;
        }
    }
    if (count != (range + 1))
        return false;
    // All range elements are present
    return true;
}

// Returns true if mat[][] is magic
// square, else returns false.
bool isMagicSquare(int **mat, int N)
{
    if (check_elements(mat, N) == false)
        return false;

    // calculate the sum of
    // the prime diagonal
    int sum = 0, sum2 = 0;
    for (int i = 0; i < N; i++)
        sum = sum + mat[i][i];
    // the secondary diagonal
    for (int i = 0; i < N; i++)
        sum2 = sum2 + mat[i][N - 1 - i];

    if (sum != sum2)
        return false;

    // For sums of Rows
    for (int i = 0; i < N; i++)
    {

        int rowSum = 0;
        for (int j = 0; j < N; j++)
            rowSum += mat[i][j];

        // check if every row sum is
        // equal to prime diagonal sum
        if (rowSum != sum)
            return false;
    }

    // For sums of Columns
    for (int i = 0; i < N; i++)
    {

        int colSum = 0;
        for (int j = 0; j < N; j++)
            colSum += mat[j][i];

        // check if every column sum is
        // equal to prime diagonal sum
        if (sum != colSum)
            return false;
    }

    return true;
}

// driver program to
// test above function
int main()
{
    int n;
    string line;
    do
    {
        scanf("%d", &n);

    } while ((n < 1) || (n > 150));
    int **array;
    array = new int *[n];
    for (int i = 0; i < n; i++)
        array[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << "a[" << i << "][" << j << "] = ";
            scanf("%d", &array[i][j]);
        }
       
    }

    if (isMagicSquare(array, n))
        cout << "Magic Square" << endl;
    else
        cout << "Not a magic Square" << endl;

    return 0;
}
