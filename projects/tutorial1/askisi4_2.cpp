#include <iostream>
#include <numeric>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    int n, i, j,k,temp,temp2,  num[8],res;
    cout << "Ποιά δύναμη θέλεις να υπολογίσεις;";
    cin >> n;

    auto start = high_resolution_clock::now();
    int lim=9*pow(9,n);

    for (i = 0; i <= lim; i++)
    {
        temp=i;
        for (j=8;j>0;j--){
            int power=(int) pow(10,j-1);
            num[8-j]=temp / power;
            temp = temp % power;
        }
        for (j=0;j<5;j++){
            temp=0;
            for (k=0;k<j;k++){
                temp+=num[k]*pow(10,8-k);
            }
            temp2=0;
            for (k=0;k<j;k++){
                temp2+=pow(num[k],n);
            }
            if (temp2 + pow(num[j],n) > temp + (num[j]+1)*pow(10,8-j)) {
                i=temp+(num[j]+1)*pow(10,8-j);
            }
        }
        res=0;
        for (j=8;j>0;j--){
            res+= (int) pow(num[j],n);
        }
        if (res==i) cout << i << endl;
        // if (pow(i, 4.0) > (i + 1) * 1000)
        //     continue;
      
            //  if (pow(j, 4.0) > i*1000+(j + 1) * 100)
            //      continue;
      
                //  if (pow(k, 4.0) > i*1000+ j*100+ (k + 1) * 10)
                //      continue;

                    // num = pow(i, 4.0) + pow(j, 4.0) + pow(k, 4.0) + pow(l, 4.0);
                    // // cout << num << endl;            
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
}