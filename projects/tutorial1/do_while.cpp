#include <iostream>
using namespace std;
int main()
{
    
    int i;
    do
    {
        std::cout << "Dose thetiko akeraio: ";
        std::cin >> i;
        std::cout << '\n';
    } while (i <= 0);

    cout << "i = " << i << endl;
}