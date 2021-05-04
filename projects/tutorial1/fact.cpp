#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;
int main()
{
    int num, fact, total;
    cout << "Ποιό παραγοντικό θέλεις να υπολογίσεις;";
    cin >> num;

    total = 1;
    for (fact = 1; fact <= num; fact++)
    {
        total *= fact;
    }

    cout << "Το παραγoντικό του " << num << " είναι " << total << endl;
}