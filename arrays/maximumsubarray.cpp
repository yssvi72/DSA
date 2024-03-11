// Approach 1: 
// C++ program to print largest contiguous array sum
#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here = max_ending_here + a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

// Driver Code
int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);

	// Function Call
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}
//Approach 2: 
// C++ program to print largest contiguous array sum
#include <bits/stdc++.h>
using namespace std;

void maxSubArraySum(int a[], int size)
{
	vector<int> dp(size, 0);
	dp[0] = a[0];
	int ans = dp[0];
	for (int i = 1; i < size; i++) {
		dp[i] = max(a[i], a[i] + dp[i - 1]);
		ans = max(ans, dp[i]);
	}
	cout << ans;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);
	maxSubArraySum(a, n);
	return 0;
}


