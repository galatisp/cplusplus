
#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main()
{
    auto start = high_resolution_clock::now();
    unsigned int exponent;
    unsigned int num[8];
    cout << "Ποιά δύναμη θέλεις να υπολογίσεις;";
    std::cin >> exponent;
   

    int lim = 8 * pow(9, exponent);
    cout << "Limit = " << lim;
    
    

    for (unsigned int i = 0; i <= lim; i++)
    {
        // sum of i's digits to the power of "exponent"
        unsigned int thisSum = 0;

        // split current number into its digit
        unsigned int reduce = i;
        int pos = 7;
        while (reduce > 0)
        {
            // take the right-most digit
            unsigned int digit = reduce % 10;
           
            // and remove it
            reduce /= 10;

            // compute digit^exponent, could use pow() as well
            unsigned int power = 1;
            for (unsigned int j = 1; j <= exponent; j++)
                power *= digit;

            // add to thisSum
            thisSum += power;
          
            pos--;
        }

        // sum of digits^n equal to the original number ?
        if (thisSum == i)
            std::cout << thisSum << std::endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() / 1000 << " milliseconds" << endl;
    return 0;
}
