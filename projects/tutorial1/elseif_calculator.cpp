#include <iostream>
using namespace std;
int main()
{
    double x1, x2; // Τα ορίσματα της πράξης
    unsigned char oper; // Το σύμβολο της πράξης
    cin >> x1 >> oper >> x2;
    if (oper == '+') cout << (x1 + x2) << endl;
    else if (oper == '-') cout << (x1 - x2) << endl;
    else if (oper == '*') cout << (x1 * x2) << endl;
    else if (oper == '/')
        if (x2 != 0) cout << (x1 / x2) << endl;
        else
            cout << " Δεν γίνεται" << endl;
    else
        cout << " Η πράξη (+,-,*,/) στην πρώτη θέση" << endl;
}