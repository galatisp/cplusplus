// C++ program to find given two array
// are equal or not using hashing technique
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#define N 50000
using namespace std;

// Returns true if arr1[0..n-1] and arr2[0..m-1]
// contain same elements.
bool areEqual(int arr1[], int arr2[], int n, int m)
{
	// If lengths of arrays are not equal
	if (n != m)
		return false;

	// Store arr1[] elements and their counts in
	// hash map
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
		mp[arr1[i]]++;

	// Traverse arr2[] elements and check if all
	// elements of arr2[] are present same number
	// of times or not.
	for (int i = 0; i < n; i++) {
		// If there is an element in arr2[], but
		// not in arr1[]
		if (mp.find(arr2[i]) == mp.end())
			return false;

		// If an element of arr2[] appears more
		// times than it appears in arr1[]
		if (mp[arr2[i]] == 0)
			return false;

		mp[arr2[i]]--;
	}

	return true;
}

// Driver Code
int main()
{
	 int arr1[N], arr2[N];
    fstream fp;
    int num;
    
    
    fp.open("random_numbers.txt", ios::in);
    int i = 0;
    while ((fp >> num) && (i<N))
    {   
         
        arr1[i++] = num;
    }

    fp.close();

    fp.open("random_numbersB.txt", ios::in);
    i = 0;
    while ((fp >> num) && (i<N))
    {   
         
        arr2[i++] = num;
    }

    fp.close();


    // mergeSort(arr1, 0, n - 1);
    // mergeSort(arr2, 0, n - 1);
	int n = sizeof(arr1) / sizeof(int);
	int m = sizeof(arr2) / sizeof(int);

	if (areEqual(arr1, arr2, n, m))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
