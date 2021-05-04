#include <iostream>
using namespace std;
int main()
{
    double x1, x2; // Τα ορίσματα της πράξης
    unsigned char oper; // Το σύμβολο της πράξης
    cin >> x1 >> oper >> x2;
    
    switch (oper){
        case '+':
            cout << (x1 + x2) << endl;
            break;
        case '-':
            cout << (x1 - x2) << endl;
            break; 
        case '*':
            cout << (x1 * x2) << endl;
            break;
        case '/':
            if (x2 != 0) cout << (x1 / x2) << endl;
                else
            cout << " Δεν γίνεται" << endl; 
            break;
        default:
            cerr << "wrong operation\n";     
    }
    
}