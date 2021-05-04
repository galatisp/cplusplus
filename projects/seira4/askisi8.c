#include <stdio.h>
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

void main()
{
    int table[SIZE][SIZE];
    int sub_table[SIZE];
    int min[SIZE];
    int max[SIZE];
    int athroisma;
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
          
            scanf("%d", &table[i][j]);
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
    printf("Minimum = %d\n", minimum(min,m));


    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
        {
          sub_table[j] = table[i][j];
          
        }
        max[i] = maximum(sub_table, m);
      
    }
    printf("Maximum = %d\n", maximum(max,n));
    
}