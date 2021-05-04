#include <iostream> 
using namespace std; 

// Function to check the array for elements in 
// given range 
bool check_elements(int arr[], int n, int range) 
{ 
	

	// Traversing the array 
	for (int i = 0; i < n; i++) { 

		// If an element is in range 
		if (abs(arr[i]) >= 0 && abs(arr[i]) <= range) { 

			// Negating at index ‘element’ 
			int z = abs(arr[i]); 
			if (arr[z] > 0) { 
				arr[z] = arr[z] * -1; 
			} 
		} 
	} 

	// Checking whether elements in range 0-range 
	// are negative 
	int count=0; 
	for (int i = 0; i <= range && i<n; i++) { 

		// Element from range is missing from array 
		if (arr[i] > 0) 
			return false; 
		else
			count++; 
	} 
	if(count!= (range+1)) 
		return false; 
	// All range elements are present 
	return true; 
} 

// Driver code 
int main() 
{ 
	// Defining Array and size 
	int arr[] = { 6, 1, 4, 5, 2, 7, 0, 3, 8 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	
	int range = 7; 

	// True denotes all elements were present 
	if (check_elements(arr, n, range)) 
		cout << "Yes"; 

	// False denotes any element was not present 
	else
		cout << "No"; 

	return 0; 
}
