/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#define N 1000
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver Code
int main()
{
    int arr[N];
    fstream fp;
    int num;
        
    fp.open("numbers.txt", ios::in);
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    while ((fp >> num) && (i<N))
    {   
         
        arr[i++] = num;
    }


    // quickSort(arr, 0, n - 1);
    cout << "Array1: \n";
    printArray(arr, n);
    return 0;
}
