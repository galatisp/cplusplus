#include <iostream>
#include <iomanip>
using namespace std;
#define SIZE 100

typedef int list[SIZE];

int minimum(list a, int N)
{
    int min = a[0];
    for (int i = 1; i < N; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

int maximum(list a, int N)
{
    int max = a[0];
    for (int i = 1; i < N; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int main()
{
    int table[SIZE][SIZE];
    int sub_table[SIZE];
    int min[SIZE];
    int max[SIZE];
    int athroisma;
    string line;
    int i, j, m, n;
    do
    {
        cout << "Dose plithos grammwn [1,100]";
        getline(cin, line);
        stringstream(line) >> n;
    } while ((n < 1) || (n > 100));

    do
    {
        cout << "Dose plithos stilwn [1,100]";
        getline(cin, line);
        stringstream(line) >> m;
    } while ((m < 1) || (m > 100));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {

            cin >> table[i][j];
        }
    }

    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            sub_table[i] = table[i][j];
        }
        min[j] = minimum(sub_table, n);
    }
    cout << "Maximum of Minimums = " << maximum(min, m) << endl;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            sub_table[j] = table[i][j];
        }
        max[i] = maximum(sub_table, m);
    }
    cout << "Minimum of Maximums = " << minimum(max, n) << endl;
}