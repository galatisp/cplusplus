#include <iostream>
#include <iomanip>
using namespace std;
#define SIZE 19

int main()
{
    int table[SIZE][SIZE];

    string line;
    int i, j, k, h, n;
    do
    {
        cout << "Dose plithos grammwn (Perittos [1,19])";
        // getline(cin, line);
        // stringstream(line) >> n;
        scanf("%d", &n);
        
    } while ((n < 1) || (n > SIZE) || (n % 2 == 0));

    i = n / 2;
    j = n ;
    k = 0;

    for (h = 0; h < n; h++)
    {
        j = j - 1;
        table[i][j] = k;
        k = k + 1;
        
        for (int m = 1; m < n; m++)
        {
            j = (j + 1) % n;
            i = (i + 1) % n;
            table[i][j] = k;
            k++;
        }
       
    }

     

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {

            cout << table[i][j] << "\t";
        }
        cout << "\n";
    }

   
  
}