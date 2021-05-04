#include <iostream>
#include <numeric>
#include <cmath>

double gcd(double a, double b)
{
    double temp;
    if (a>b) {
        temp = a;
        a = b;
        b = temp;
    }

    
    while (fmod(b,a) > 0)  {
        temp = fmod(b,a);
        a = b;
        b = temp;
    }
    return b;
    
    
}


double lcm(double a, double b)
{
    double temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main()
{
    double res1 =  gcd(25, 15);
    std::cout << "ΜΚΔ " << res1 << '\n';

    double result =  lcm(25, 15);

    std::cout << "ΕΚΠ " <<result << '\n';
}
