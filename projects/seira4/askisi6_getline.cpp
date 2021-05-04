#include <iostream>
#include <numeric>
#include <string.h>
#include <stdio.h>
#include <string>
#include <sstream>
#define LINES 100 /* Max Lines */
#define LEN 256   /* Max string length */
using namespace std;



int check(char buf[LEN])
{
    // char buf[LEN];

    // int c;
    // puts("Enter text. Include a newline to exit:");
    // int i = 0;
    // do
    // {
    //     c = getchar();
    //     buf[i] = c;
    //     i++;
    // } while (c != '\n');

    
    

    buf[strcspn(buf, "\n")] = '\0';
    int len = strlen(buf);

    if (len > 20)
    {
        return -1;
    }

    if (len == 0)
    {
        return 0;
    }

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
        return 1;
    }
    else
    {
        return 2;
    }
}

int main()
{
    int res[LINES];
    int n = 2;
    char line[LEN];

    string mystr;

    do
    {
        cout << "Dose plithos symboloseiron (<=100) : ";
        getline(cin, mystr);
        stringstream(mystr) >> n;
       
    } while (n > LINES);

    for (int i = 0; i < n; i++)
    {
        fgets(line, sizeof(line), stdin);
        res[i] = check(line);
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (res[i] == -1)
            cout << "error" << endl;
        else if (res[i] == 0)
            cout << "empty" << endl;
        else if (res[i] == 1)
            cout << "ok" << endl;
        else if (res[i] == 2)
            cout << "no" << endl;
    }
}