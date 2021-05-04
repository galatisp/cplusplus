#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;



int main()
{
    for (int a = 1000; a<=9999; a++){
        int a1, a2, a3, a4, temp;
        a1 = a / 1000;
        temp = a % 1000;
        a2 = temp / 100;
        temp = temp % 100;
        a3 = temp / 10;
        a4 = temp % 10;

        if (pow(a1,4) + pow(a2,4)+ pow(a3,4) + pow(a4,4) == a){
            cout << a << endl;
        }

        
    }
}