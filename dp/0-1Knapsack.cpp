/* Given N items where each item has some weight and profit associated with it 
and also given a bag with capacity W, [i.e., the bag can hold at most W weight in it]. 
The task is to put the items into the bag such that the sum of profits associated with them is the maximum possible. 
*/
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*Follow the below steps to solve the problem:
The maximum value obtained from ‘N’ items is the max of the following two values. 
Case 1 (include the Nth item): Value of the Nth item plus maximum value obtained by remaining N-1 items and remaining weight i.e. (W-weight of the Nth item).
Case 2 (exclude the Nth item): Maximum value obtained by N-1 items and W weight.
If the weight of the ‘Nth‘ item is greater than ‘W’, then the Nth item cannot be included and Case 2 is the only possibility.
*/
/* A Naive recursive implementation of 
0-1 Knapsack problem */
#include <bits/stdc++.h> 
using namespace std; 

// A utility function that returns 
// maximum of two integers 
int max(int a, int b) { return (a > b) ? a : b; } 

// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 

	// Base Case 
	if (n == 0 || W == 0) 
		return 0; 

	// If weight of the nth item is more 
	// than Knapsack capacity W, then 
	// this item cannot be included 
	// in the optimal solution 
	if (wt[n - 1] > W) 
		return knapSack(W, wt, val, n - 1); 

	// Return the maximum of two cases: 
	// (1) nth item included 
	// (2) not included 
	else
		return max( 
			val[n - 1] 
				+ knapSack(W - wt[n - 1], wt, val, n - 1), 
			knapSack(W, wt, val, n - 1)); 
} 

// Driver code 
int main() 
{ 
	int profit[] = { 60, 100, 120 }; 
	int weight[] = { 10, 20, 30 }; 
	int W = 50; 
	int n = sizeof(profit) / sizeof(profit[0]); 
	cout << knapSack(W, weight, profit, n); 
	return 0; 
} 
//TC-O(2^N) , SC-O(N)------------------------------------------------------------------------------------------------------------------------------------------
//Memorization Approach:It should be noted that the above function using recursion computes the same subproblems again and again. See the following recursion tree, K(1, 1) is being evaluated twice. 
// Here is the top-down approach of 
// dynamic programming 
#include <bits/stdc++.h> 
using namespace std; 

// Returns the value of maximum profit 
int knapSackRec(int W, int wt[], int val[], int index, int** dp) 
{ 
	// base condition 
	if (index < 0) 
		return 0; 
	if (dp[index][W] != -1) 
		return dp[index][W]; 

	if (wt[index] > W) { 

		// Store the value of function call 
		// stack in table before return 
		dp[index][W] = knapSackRec(W, wt, val, index - 1, dp); 
		return dp[index][W]; 
	} 
	else { 
		// Store value in a table before return 
		dp[index][W] = max(val[index] 
						+ knapSackRec(W - wt[index], wt, val, 
										index - 1, dp), 
					knapSackRec(W, wt, val, index - 1, dp)); 

		// Return value of table after storing 
		return dp[index][W]; 
	} 
} 

int knapSack(int W, int wt[], int val[], int n) 
{ 
	// double pointer to declare the 
	// table dynamically 
	int** dp; 
	dp = new int*[n]; 

	// loop to create the table dynamically 
	for (int i = 0; i < n; i++) 
		dp[i] = new int[W + 1]; 

	// loop to initially filled the 
	// table with -1 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < W + 1; j++) 
			dp[i][j] = -1; 
	return knapSackRec(W, wt, val, n - 1, dp); 
} 

// Driver Code 
int main() 
{ 
	int profit[] = { 60, 100, 120 }; 
	int weight[] = { 10, 20, 30 }; 
	int W = 50; 
	int n = sizeof(profit) / sizeof(profit[0]); 
	cout << knapSack(W, weight, profit, n); 
	return 0; 
}
//TC-O(N * W) , SC-: O(N * W) + O(N).-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Bottom up approach
// A dynamic programming based 
// solution for 0-1 Knapsack problem 
#include <bits/stdc++.h> 
using namespace std; 

// A utility function that returns 
// maximum of two integers 
int max(int a, int b) { return (a > b) ? a : b; } 

// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
	int i, w; 
	vector<vector<int> > K(n + 1, vector<int>(W + 1)); 

	// Build table K[][] in bottom up manner 
	for (i = 0; i <= n; i++) { 
		for (w = 0; w <= W; w++) { 
			if (i == 0 || w == 0) 
				K[i][w] = 0; 
			else if (wt[i - 1] <= w) 
				K[i][w] = max(val[i - 1] 
								+ K[i - 1][w - wt[i - 1]], 
							K[i - 1][w]); 
			else
				K[i][w] = K[i - 1][w]; 
		} 
	} 
	return K[n][W]; 
} 

// Driver Code 
int main() 
{ 
	int profit[] = { 60, 100, 120 }; 
	int weight[] = { 10, 20, 30 }; 
	int W = 50; 
	int n = sizeof(profit) / sizeof(profit[0]); 

	cout << knapSack(W, weight, profit, n); 

	return 0; 
} 

// TC-O(N*W) , SC-O(N*W)------------------------------------------------------------------------------------------------------------------------------------------------------
//Dynamic programming: 
// C++ program for the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find the maximum profit 
int knapSack(int W, int wt[], int val[], int n) 
{ 
	// Making and initializing dp array 
	int dp[W + 1]; 
	memset(dp, 0, sizeof(dp)); 

	for (int i = 1; i < n + 1; i++) { 
		for (int w = W; w >= 0; w--) { 

			if (wt[i - 1] <= w) 
				
				// Finding the maximum value 
				dp[w] = max(dp[w], 
							dp[w - wt[i - 1]] + val[i - 1]); 
		} 
	} 
	// Returning the maximum value of knapsack 
	return dp[W]; 
} 

// Driver code 
int main() 
{ 
	int profit[] = { 60, 100, 120 }; 
	int weight[] = { 10, 20, 30 }; 
	int W = 50; 
	int n = sizeof(profit) / sizeof(profit[0]); 
	cout << knapSack(W, weight, profit, n); 
	return 0; 
}
//T(C)-O(N*W) , SC-O(W)


