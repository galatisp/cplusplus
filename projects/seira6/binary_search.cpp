// C++ program to implement recursive Binary Search
#include <cstdlib>
#include <ctime>
#include <iostream>
#define N 100
#define Limit 1000
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		cout << "Binary Search Left: "<<l<<" Right: "<<r<<" Mid: "<<mid<<endl;
		cout << "Mid element: "<< arr[mid]<< endl;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]

	// Initial index of first subarray
	int i = 0;

	// Initial index of second subarray
	int j = 0;

	// Initial index of merged subarray
	int k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of
	// L[], if there are any
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l >= r)
	{
		return; //returns recursively
	}
	int m = l + (r - l) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
}


/* Function to print an array */
void printArray(int arr[], int size)
{
	int i, count=0;
	for (i = 0; i < size; i++)
	{
		printf("a[%d]= %d", i, arr[i]);
		count++;
		if ((count % 5 == 0) ){
			printf("\n");
			count=0;
		}
		else{
			printf(" \t ");
		}
			
	}
	cout << endl;
}

int main(void)
{
	int arr[N];
	int key;

	srand((unsigned)time(0));

	for (int i = 0; i < N; i++)
	{
		arr[i] = (rand() % Limit) + 1;
	}

	mergeSort(arr, 0, N-1);

	printArray(arr, N);


	do
	{
		printf("Give the number to search:[1-%d]", Limit);
		scanf("%d", &key);
	} while ((key < 1) || (key > Limit));

	int result = binarySearch(arr, 0, N - 1, key);
	
	(result == -1) ? cout << "Element is not present in array" << endl
				   : cout << "Element is present at index " << result << endl;

	return 0;
}
