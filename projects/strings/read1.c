#include <stdio.h>
int main()
{
    int n = 0;
    while (1)
    {
        int c = getchar();
        if (c == '\n')
            break;
        putchar(c);
    }
}