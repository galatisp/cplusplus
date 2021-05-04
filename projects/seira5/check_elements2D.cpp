#include <iostream>
#include <iomanip>
#define N 3
using namespace std;

// Function to check the array for elements in
// given range
bool check_elements(int** arr, int n)
{
    int range = n*n-1;

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

    // Traversing the array
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            cout << arr[i][j] << '\t';
        }
        cout << endl;
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

// Driver code
int main()
{
    int n;
    string line;
    do
    {
        cout << "Dose plithos grammwn [1,150]: ";
        getline(cin, line);
        stringstream(line) >> n;

    } while ((n < 1) || (n > 150));
    int **array;
    array = new int *[n];
    for (int i = 0; i < n; i++)
        array[i] = new int[n];
   
     for (int i = 0; i < n; i++)   
      for (int j = 0; j < n; j++){
          cout << "a["<<i<<"]["<<j<<"] = ";
          cin >> array[i][j];
      } 
   
    

   
   
    // True denotes all elements were present
    if (check_elements(array, n))
        cout << "Yes";

    // False denotes any element was not present
    else
        cout << "No";

    return 0;
}
