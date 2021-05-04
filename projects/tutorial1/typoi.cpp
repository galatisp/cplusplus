#include <iostream>
#include <typeinfo>
#include <limits>
using namespace std;
int main()
{
    int counter{20000};
//     auto pi = 3.14159265358979323846f;
//     auto a = 3.14159265358979323846;
//     auto ld = 3.14159265358979323846l;
    
    char newline{'\n'};

//     cout << "Min  value of float = " << std::numeric_limits<float>::min() << endl;
//     cout << "Max  value of float = " << std::numeric_limits<float>::max() << endl
//          << endl;
//     cout << "Precision digits of float = " << std::numeric_limits<float>::digits10 << endl;
//     cout << "Precision digits of double = " << std::numeric_limits<double>::digits10 << endl;
//     cout << "Precision digits of long double = " << std::numeric_limits<long double>::digits10 << endl;

//     cout << "===================================================" << endl
//          << endl;

     double pi = 3.14;
    cout << "Μεταβλητή: "
         << "pi" << endl;
    cout << "Διεύθυνση: " << &pi << endl;
    cout << "Τύπος: " << typeid(pi).name() << endl;
    cout << "Μέγεθος: " << (sizeof pi) << endl;
    cout.precision(7);
    cout << "Τιμή: " << pi << endl;

//     cout << "===================================================" << endl
//          << endl;

//     cout << "Μεταβλητή: "
//          << "a" << endl;
//     cout << "Διεύθυνση: " << &a << endl;
//     cout << "Τύπος: " << typeid(a).name() << endl;
//     cout << "Μέγεθος: " << (sizeof a) << endl;
//     cout.precision(16);
//     cout << "Τιμή: " << a << endl;

//     cout << "===================================================" << endl
//          << endl;

//     cout << "Μεταβλητή: "
//          << "ld" << endl;
//     cout << "Διεύθυνση: " << &ld << endl;
//     cout << "Τύπος: " << typeid(ld).name() << endl;
//     cout << "Μέγεθος: " << (sizeof ld) << endl;
//     cout.precision(19);
//     cout << "Τιμή: " << ld << endl;

//     cout << "===================================================" << endl
//          << endl;

//     cout << "Min  value of int = " << std::numeric_limits<int>::min() << endl;
//     cout << "Max  value of int = " << std::numeric_limits<int>::max() << endl
//          << endl;

//     cout << "===================================================" << endl
//          << endl;

//     cout << "Μεταβλητή: "
//          << "counter" << endl;
//     cout << "Διεύθυνση: " << &counter << endl;
//     cout << "Τύπος: " << typeid(counter).name() << endl;
//     cout << "Μέγεθος: " << (sizeof counter) << endl;
//     cout << "Τιμή: " << counter << endl;

//     cout << "Emvadon = " << ld * 2 * 2 << endl;
//     cout << newline;
}