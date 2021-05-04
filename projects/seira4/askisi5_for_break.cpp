#include <iostream>
#include <numeric>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;

int mypower(int b, int e)
{
    unsigned int power = 1;
    for (unsigned int j = 1; j <= e; j++)
        power *= b;
    return power;
}

int main()
{
    unsigned int n, i, j, k, temp, sum, temp2, d1_n, d2_n, d3_n, d4_n, d5_n,d6_n,d7_n, d1_l, d2_l, d3_l, d4_l, d5_l, num[8], res;
    std::cout << "Ποιά δύναμη θέλεις να υπολογίσεις;";
    cin >> n;
    bool flag = false;

    int d1, d2, d3, d4, d5, d6, d7, d8;
    auto start = high_resolution_clock::now();
    unsigned int lim = 8 * pow(9, n);
    for (d1 = 0; d1 < 10; d1++)
    {
        d1_n = mypower(d1, n);
        d1_l = (d1)*10000000;
        if (d1_n > d1_l + 10000000)
            continue;

        for (d2 = 0; d2 < 10; d2++)
        {
            d2_n = mypower(d2, n);
            d2_l = (d2)*1000000;
            if (d1_n + d2_n > d1_l + d2_l + 1000000)
                continue;

            for (d3 = 0; d3 < 10; d3++)
            {
                d3_n = mypower(d3, n);
                d3_l = (d3)*100000;
                if (d1_n + d2_n + d3_n > d1_l + d2_l + d3_l + 100000)
                    continue;

                for (d4 = 0; d4 < 10; d4++)
                {
                    d4_n = mypower(d4, n);
                    d4_l = (d4)*10000;
                    if (d1_n + d2_n + d3_n + d4_n > d1_l + d2_l + d3_l + d4_l + 10000)
                        continue;
                    for (d5 = 0; d5 < 10; d5++)
                    {
                        d5_n = mypower(d5, n);
                        d5_l = (d5)*1000;
                        if (d1_n + d2_n + d3_n + d4_n + d5_n > d1_l + d2_l + d3_l + d4_l + d5_l + 1000)
                            continue;
                        for (d6 = 0; d6 < 10; d6++)
                        {
                            d6_n = mypower(d6, n);
                            for (d7 = 0; d7 < 10; d7++)
                            {
                                d7_n = mypower(d7, n);
                                for (d8 = 0; d8 < 10; d8++)
                                {
                                    sum = d7_n + d1_n + d2_n + d3_n + d4_n + d5_n + d6_n  + mypower(d8, n);
                                    temp = d1 * 10000000 + d2 * 1000000 + d3 * 100000 + d4 * 10000 + d5 * 1000 + d6 * 100 + d7 * 10 + d8;
                                    if (sum == temp)
                                        std::cout << temp << endl;
                                    flag = temp == lim;
                                    if (flag)
                                        break;
                                }
                                if (flag)
                                    break;
                            }
                            if (flag)
                                break;
                        }
                        if (flag)
                            break;
                    }
                    if (flag)
                        break;
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        if (flag)
            break;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "Time taken by function: "
         << duration.count() / 1000<< " milliseconds" << endl;
}