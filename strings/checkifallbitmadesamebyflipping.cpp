// C++ program to check if a single bit can
// be flipped tp make all ones
#include <bits/stdc++.h>
using namespace std;

// This function returns true if we can
// bits same in given binary string str.
bool canMakeAllSame(string str)
{
	int zeros = 0, ones = 0;

	// Traverse through given string and
	// count numbers of 0's and 1's
	for (char ch : str)
		(ch == '0') ? ++zeros : ++ones;

	// Return true if any of the two counts
	// is 1
	return (zeros == 1 || ones == 1);
}

// Driver code
int main()
{
	canMakeAllSame("101") ? printf("Yes\n") : printf("No\n");
	return 0;
}
