#include <stdio.h>
#define SIZE 100

typedef double list[SIZE];


double average(list a, int N)
{
    double sum = 0.0;
    for (int i = 0; i < N; i++)
    {
        sum += a[i];
    }
    return sum/N;
}

void main()
{
    double table[SIZE][SIZE];
    double sub_table[SIZE];
    double avg_row[SIZE];
    double avg_col[SIZE];
    int i, j, m, n;
    do
    {
        printf("Dose plithos grammwn [1,100]");
        scanf("%d", &n);
    } while ((n < 1) || (n > 100));
    
    do
    {
        printf("Dose plithos stilwn [1,100]");
        scanf("%d", &m);
    } while ((m < 1) || (m > 100));

    

    for (i = 0; i < n; i++)
    {
             for (j = 0; j < m; j++)
        {
          
            scanf("%lf", &table[i][j]);
        }
       
    }

     for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
        {
          sub_table[j] = table[i][j];
          
        }
        avg_row[i] = average(sub_table, m);
        printf("Average [Row-%d] = %.3lf\n", i, avg_row[i]);
    }
    printf("Average (Rows) = %.3lf\n", average(avg_row,n));

    for (j = 0; j < m; j++)
    {
      for (i = 0; i < n; i++)
        {
          sub_table[i] = table[i][j];
          
        }
        avg_col[j] = average(sub_table, n);
      printf("Average [Column-%d] = %.3lf\n", j, avg_col[j]);
    }
    printf("Average (Columns) = %.3lf\n", average(avg_col,m));


   
    
}