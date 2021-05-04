#include <iostream>
#include <numeric>
#include <string.h>
#include <stdio.h>
#include <string>
#include <sstream>
#define LINES 20 /* Max Lines */
#define LEN 256   /* Max string length */
using namespace std;
char output[1000];

void check(char buf[LEN])
{
    buf[strcspn(buf, "\n")] = '\0';
    int len = strlen(buf);

    if (len > 20)
    {
        strcat(output, "error\n");
    }

    else if (len == 0)
    {
        strcat(output, "empty\n");
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
        }
        else
        {
            strcat(output, "no\n");
        }
    }
}

int main()
{

    int n;
    char line[LEN];

    string mystr;

    do
    {
        cout << "Dose plithos symboloseiron (<=20) : ";
        cin >> n;

    } while (n > LINES);

    fgets(line, sizeof(line), stdin);

    for (int i = 0; i < n; i++)
    {
        fgets(line, sizeof(line), stdin);
        check(line);
    }
    cout << endl;

    cout << output;
}

