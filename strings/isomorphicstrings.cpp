//Approach 1: ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// C++ program to check if two strings are isomorphic
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256

// This function returns true if str1 and str2 are
// isomorphic
bool areIsomorphic(string str1, string str2)
{

	int m = str1.length(), n = str2.length();

	// Length of both strings must be same for one to one
	// correspondence
	if (m != n)
		return false;

	// To mark visited characters in str2
	bool marked[MAX_CHARS] = { false };

	// To store mapping of every character from str1 to
	// that of str2. Initialize all entries of map as -1.
	int map[MAX_CHARS];
	memset(map, -1, sizeof(map));

	// Process all characters one by one
	for (int i = 0; i < n; i++) {
		// If current character of str1 is seen first
		// time in it.
		if (map[str1[i]] == -1) {
			// If current character of str2 is already
			// seen, one to one mapping not possible
			if (marked[str2[i]] == true)
				return false;

			// Mark current character of str2 as visited
			marked[str2[i]] = true;

			// Store mapping of current characters
			map[str1[i]] = str2[i];
		}

		// If this is not first appearance of current
		// character in str1, then check if previous
		// appearance mapped to same character of str2
		else if (map[str1[i]] != str2[i])
			return false;
	}

	return true;
}

// Driver program
int main()
{
	cout << (areIsomorphic("aab", "xxy") ? "True" : "False")
		<< endl;
	return 0;
}

//Approach 2:  Using maps ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// C++ program to check if two strings are IsIsomorphic
#include <bits/stdc++.h>

using namespace std;

// this function returns true if str1 and str2 are
// isomorphic
bool areIsomorphic(string str1, string str2)
{

	// initializing an unordered_map to store letters from
	// str1 and str2 as key value pairs
	unordered_map<char, char> charCount;

	// iterating over str1 and str2
	for (int i = 0; i < str1.length(); i++) 
	{
	
		// if str1[i] is a key in charCount
		if (charCount.count(str1[i]))
		{
		
			// checking if the value in charCount for key
			// str1[i] is equal to str2[i]
			if (charCount[str1[i]] != str2[i]) {
				return false;
			}
		}
		// if str2[i] is not a value in charCount
		else {
			// checking if str2[i] is already a value in
			// charCount
			vector<char> values;
			for (auto it : charCount) {
				values.push_back(it.second);
			}
			if (find(values.begin(), values.end(), str2[i])
				!= values.end()) {
				return false;
			}
			else {
				charCount[str1[i]] = str2[i];
			}
		}
	}
	return true;
}

int main()
{
	// Test strings
	string str1 = "aac";
	string str2 = "xxy";

	// Function Call
	if (str1.length() == str2.length()
		&& areIsomorphic(str1, str2)) {
		cout << "True\n";
	}
	else {
		cout << "False\n";
	}
	return 0;
}
