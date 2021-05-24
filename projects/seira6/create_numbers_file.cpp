/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
#include <fstream>
#define N 50000
using namespace std;



// Driver Code
int main()
{
    ofstream fp;
    fp.open("random_numbersB.txt", ios::app);
   
    int arr[N];
     
    //write numbers to file
    int i;
    srand(time(0));
    for (i = 0; i < N; i++)
        fp << rand() << " ";

    fp.close();

 
    return 0;
}
