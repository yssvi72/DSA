/* Input: {“geeksforgeeks”, “geeks”, “geek”, “geezer”}
Output: “gee”
Input: {“apple”, “ape”, “april”}
Output: “ap”
The longest common prefix for an array of strings is the common prefix between 2 most dissimilar strings. 
For example, in the given array {“apple”, “ape”, “zebra”}, there is no common prefix because the 2 most dissimilar strings of the array “ape” and “zebra” do not share any starting characters. */
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Approach 1:  The idea is to sort the array of strings and find the common prefix of the first and last string of the sorted array.
// C++ program to find longest common prefix 
// of given array of words.
#include<iostream>
#include<algorithm>

using namespace std;

// Function to find the longest common prefix
string longestCommonPrefix(string ar[], int n)
{

	// If size is 0, return empty string
	if (n == 0)
		return "";

//If size is 1 then just return that character
	if (n == 1)
		return ar[0];

	// Sort the given array
	sort(ar, ar + n);

	// Find the minimum length from 
	// first and last string
	int en = min(ar[0].size(), 
				ar[n - 1].size());

	// Now the common prefix in first and 
	// last string is the longest common prefix
	string first = ar[0], last = ar[n - 1];
	int i = 0;
	while (i < en && first[i] == last[i])
		i++;

	string pre = first.substr(0, i);
	return pre;
}

// Driver Code
int main()
{
	string ar[] = {"geeksforgeeks", "geeks", 
						"geek", "geezer"};
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << "The longest common prefix is: "
		<< longestCommonPrefix(ar, n);
	return 0;
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Approach 2: The Idea is to find unique prefix without sorting the string array. Extract substring by comparing current substring with  the previous substring and update it’s result. For large string it work much faster.
#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(string arr[], int n)
{
	// take temp_prefix string and assign first element of
	// arr : a.
	string result = arr[0];
	int len = result.length();

	// Iterate for rest of element in string.
	for (int i = 1; i < n; i++) {
		// .find() return index of that substring from
		// string.
		while (arr[i].find(result) != 0) {

			// update matched substring prefx
			result = result.substr(0, len - 1);
			len--;

			// check for empty case. direct return if true..
			if (result.empty()) {
				return "-1";
			}
		}
	}
	return result;
}

/* Driver Function to test other function */
int main()
{
	string input[]
		= { "geeksforgeeks", "geeks", "geek", "geezer" };
	int n = sizeof(input) / sizeof(input[0]);
	cout << "The longest Common Prefix is : "
		<< longestCommonPrefix(input, n);
	return 0;
}

