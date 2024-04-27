// C++ code to implement Prefix sum approach
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// The main function to find the K-th largest sum of
// contiguous subarray using Prefix Sum and Sorting
// approach.
int kthLargestSum(vector<int>& arr, int k)
{
	int n = arr.size();

	// Create a prefix sum array.
	vector<int> prefixSum(n + 1);
	prefixSum[0] = 0;
	for (int i = 1; i <= n; i++) {
		prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
	}

	// Create a vector to store all possible subarray sums.
	vector<int> subarraySums;
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			subarraySums.push_back(prefixSum[j]
								- prefixSum[i]);
		}
	}

	// Sort the subarray sums in decreasing order.
	sort(subarraySums.begin(), subarraySums.end(),
		greater<int>());

	// Return the K-th largest sum of contiguous subarray.
	return subarraySums[k - 1];
}
// Driver Code
int main()
{
	vector<int> arr = { 10, -10, 20, -40 };
	int k = 6;
	cout << kthLargestSum(arr, k)
		<< endl; // expected output is -10

	return 0;
}
// This code is contributed by Veerendra_Singh_Rajpoot
