#include <iostream>
#include <string>
#include <sstream>
using namespace std;
bool isletter(char c)
{
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

int main()
{
    int c, lines = 0, chars = 0, words = 0;
    c = getchar();
    while (c != EOF)
        if (isletter(c))
        {
            words++;
            do
            {
                chars++;
                c = getchar();
            } while (isletter(c));
        }
        else
        {
            chars++;
            if (c == '\n')
                lines++;
            c = getchar();
        }
    printf("%d lines were read\n", lines);
    printf("%d words were read\n", words);
   
}