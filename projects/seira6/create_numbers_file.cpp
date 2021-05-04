/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
#include <fstream>
#define N 50000
using namespace std;



// Driver Code
int main()
{
    ofstream fp;
    fp.open("numbers.txt", ios::app);
   
    int arr[N];
     
    //write numbers to file
    int i;
    for (i = 0; i < N; i++)
        fp << i << " ";

    fp.close();

 
    return 0;
}
