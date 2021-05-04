#include <iostream>
#include <iomanip>
using namespace std;
#define SIZE 100

typedef double list[SIZE];

double average(list a, int N)
{
    double sum = 0.0;
    for (int i = 0; i < N; i++)
    {
        sum += a[i];
    }
    return sum / N;
}

int main()
{
    double table[SIZE][SIZE];
    double sub_table[SIZE];
    double avg_row[SIZE];
    double avg_col[SIZE];
    string line;
    int i, j, m, n;
    do
    {
        cout << "Dose plithos grammwn [1,100]: ";
        getline(cin, line);
        stringstream(line) >> n;

    } while ((n < 1) || (n > 100));

    do
    {
        cout << "Dose plithos stilwn [1,100]: ";
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

    cout << fixed; //fixed floating-point notation
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            sub_table[j] = table[i][j];
        }
        avg_row[i] = average(sub_table, m);

        cout << "Average [Row-" << i << "] = " << setprecision(3) << avg_row[i] << endl;
    }

    cout << "Average Rows = " << setprecision(3) << average(avg_row, n) << endl;
    cout << fixed; //fixed floating-point notation
    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            sub_table[i] = table[i][j];
        }
        avg_col[j] = average(sub_table, n);
        cout << "Average [Col-" << j << "] = " << setprecision(3) << avg_col[j] << endl;
    }

    cout << "Average Columns = " << setprecision(3) << average(avg_col, m) << endl;
}