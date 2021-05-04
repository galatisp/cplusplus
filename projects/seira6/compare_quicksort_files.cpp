/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#define N 50000
using namespace std;

// A utility function to swap two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
		at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool compare(int *A, int *B, int n){
     // Compare corresponding elements
    for (int i = 0; i < n; i++)
        if (A[i] != B[i])
            return false;       
     
    return true;
}

// Driver Code
int main()
{
    int arr1[N], arr2[N];
    fstream fp;
    int num, n;
    string line;
    // do
    // {
    //     cout << "Dose plithos grammwn [1,1000]";
    //     getline(cin, line);
    //     stringstream(line) >> n;
    // } while ((n < 1) || (n > 100));
    n = N;    
    fp.open("numbers.txt", ios::in);
    int i = 0;
    while ((fp >> num) && (i<N))
    {   
         
        arr1[i++] = num;
    }

    fp.close();

    fp.open("numbers2.txt", ios::in);
    i = 0;
    while ((fp >> num) && (i<N))
    {   
         
        arr2[i++] = num;
    }

    fp.close();


    quickSort(arr1, 0, n - 1);
    quickSort(arr2, 0, n - 1);
   
    if (compare(arr1, arr2, n))
        cout << "Arrays contain the same elements \n";
    else
        cout << "Arrays do not contain the same elements \n";
   
    // printArray(arr1, n);
    // printArray(arr2, n);

    return 0;
}
