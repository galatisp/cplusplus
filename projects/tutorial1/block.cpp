#include <iostream>
#include <typeinfo>
#include <limits>
using namespace std;
int main()
{
    double x{3.2};
    { // begin block B
        int x{5};
        cout << "in inner block B x=" << x << endl; // prints 5
    }                                               // end block B
    cout << "in main block  x=" << x << endl;
}