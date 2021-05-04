#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;
int main()
{
     double a, b, c;
     double x1, x2;
     double delta;
     cout << "Δώσε τρεις πραγματικούς αριθμούς" << endl;
     cin >> a >> b >> c;
     cout << " a = " << a << " b = " << b
          << " c = " << c << endl;
     delta = b * b - 4 * a * c;
     
     x1 = (-b + sqrt(delta)) / (2 * a);
     x2 = (-b - sqrt(delta)) / (2 * a);
     cout << " Λύση1 = " << x1
          << " Λύση2 = " << x2 << endl;
     return 0;
}
