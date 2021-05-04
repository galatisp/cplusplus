/* C++ implementation of QuickSort */

#include <iostream>
#include <iomanip>
#define N 50000
using namespace std;

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
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

bool compare(int *A, int *B, int n)
{
	// Compare corresponding elements
	for (int i = 0; i < n; i++)
		if (A[i] != B[i])
			return false;

	return true;
}


// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
	
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

bool find(int *A, int n, int key){
	int pos = 0;
	
	while ( pos < n) {
		if (A[pos]==key){
			return true;
		}
		pos++;
	}

	return false;

}

int minDiffPos(int *A, int *B, int n){
    
	int pos = 0;
	while ((pos < n) && (A[pos] == B[pos])){
		pos++;
	}
    
    return pos;
}


int maxDiffPos(int *A, int *B, int n){
    
	int pos = n - 1;
	while ((pos >= 0) && (binarySearch(B, 0, n-1, A[pos])>= 0)){
		pos--;
	}
    
    return pos;
}

// Driver Code
int main()
{
	int arr1[N], arr2[N];

	int num, n;
	
	do
	{
		//    printf("Dose plithos arithmon:");
		scanf("%d", &n);
	} while ((n < 1) || (n > N));

	int i = 0;
	while (i < n)
	{
		scanf("%d", &arr1[i++]);
	}

	i = 0;
	while (i < n)
	{
		scanf("%d", &arr2[i++]);
	}

	mergeSort(arr1, 0, n - 1);
	mergeSort(arr2, 0, n - 1);
	// printf("n = %d\n", n);
	if (compare(arr1, arr2, n))
		cout << "Arrays contain the same elements \n";
	else{
		cout << "Arrays do not contain the same elements \n";
		int minPos = minDiffPos(arr1, arr2, n);
		cout << arr1[minPos]<<endl;
		int maxPos = maxDiffPos(arr1, arr2, n);
		cout << arr1[maxPos]<<endl;
	}

	printArray(arr1, n);
	printArray(arr2, n);

	return 0;
}
