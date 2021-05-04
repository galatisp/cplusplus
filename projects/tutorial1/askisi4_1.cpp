#include <iostream>
#include <numeric>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    int num, fact, i, j, k, l;
    // cout << "Ποιό παραγοντικό θέλεις να υπολογίσεις;";
    // cin >> num;

    auto start = high_resolution_clock::now();
    for (i = 1; i < 10; i++)
    {
        if (pow(i, 4.0) > (i + 1) * 1000)
            continue;
        for (j = 0; j < 10; j++)
        {
            //  if (pow(j, 4.0) > i*1000+(j + 1) * 100)
            //      continue;
            for (k = 0; k < 10; k++)
            {
                //  if (pow(k, 4.0) > i*1000+ j*100+ (k + 1) * 10)
                //      continue;
                for (l = 0; l < 10; l++)
                {
                    num = pow(i, 4.0) + pow(j, 4.0) + pow(k, 4.0) + pow(l, 4.0);
                    // cout << num << endl;
                    if (num == i * 1000 + j * 100 + k * 10 + l)
                    {
                        cout << num << endl;
                    }
                }
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
}