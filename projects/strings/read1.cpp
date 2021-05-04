#include <iostream>
int main()
{
    int i = 0;
    int c;
    char line[200];
    int n;

    scanf("%d\n", &n);

    for (int j = 0; j < n; j++)
    {
        while ((c = getchar()) != '\n')
        {
            line[i++] = c;
        }
        line[i] = '\0';
       
         printf("Line %d= %s\n", j, line);
    }

    

    // std::cout << "Line = " << line<<std::endl;
   
}