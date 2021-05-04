#include <iostream>
#include <numeric>
#include <string.h>
#include <stdio.h>
#include <string>
#include <sstream>
#define LINES 20 /* Max Lines */
#define LEN 256  /* Max string length */
using namespace std;
char output[100000];

void check(char buf[LEN])
{
    buf[strcspn(buf, "\n")] = '\0';
    int len = strlen(buf);

    if (len > 20)
    {
        strcat(output, "error\n");
        // printf("error\n");
    }

    else if (len == 0)
    {
        strcat(output, "empty\n");
        // printf("empty\n");
        return;
    }
    else // normal input
    {
        bool pallindromo = true;

        for (int i = 0; i < len / 2; i++)
        {
            if (buf[i] != buf[len - 1 - i])
            {
                pallindromo = false;
                break;
            }
        }

        if (pallindromo)
        {
            strcat(output, "ok\n");
            // printf("ok\n");
        }
        else
        {
            strcat(output, "no\n");
            // printf("no\n");
        }
    }
}

int main()
{

    int n, c;
    char line[LEN];

   
    do
    {
        printf("Dose plithos symboloseiron (>0) : ");
        scanf("%d\n", &n);

     } while (n <= 0);

    for (int j = 0; j < n; j++)
    {
        int i =0;
        while ((c = getchar()) != '\n')
        {
            line[i++] = c;
        }
        line[i] = '\0';
        check(line);
        

    }
    
     cout << output;
}
