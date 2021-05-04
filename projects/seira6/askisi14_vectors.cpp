// C++ program to implement Naive approach
// to remove duplicates
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool areSameSet(vector<int> A, vector<int> B)
{
	int n = A.size();
	if (B.size() != n)
		return false;

	// Create a hash table to
	// number of instances
	unordered_map<int, int> m;

	// for each element of A
	// increase it's instance by 1.
	for (int i = 0; i < n; i++)
		m[A[i]]++;
	
	// for each element of B
	// decrease it's instance by 1.
	for (int i = 0; i < n; i++)
		m[B[i]]--;
	
	// Iterate through map and check if
	// any entry is non-zero
	for (auto i : m)
		if (i.second != 0)
			return false;
	
	return true;
}

int main()
{
	vector<int> A, B;
	A.push_back(12);
	A.push_back(15);
	A.push_back(10);
	A.push_back(6);
	A.push_back(8);
	A.push_back(4);
	A.push_back(2);

	B.push_back(2);
	B.push_back(5);
	B.push_back(6);
	B.push_back(8);
	B.push_back(10);
	B.push_back(12);
	B.push_back(15);

	areSameSet(A, B)? cout << "Yes" : cout << "No";
}
