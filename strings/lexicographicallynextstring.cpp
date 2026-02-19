/* Given a string, find lexicographically next string
Input : geeks
Output : geekt
The last character 's' is changed to 't'.
If string is empty, we return ‘a’. If string contains all characters as ‘z’, we append ‘a’ at the end. Otherwise we find first character from end which is not z and increment it.*/
// C++ program to find lexicographically next
// string
#include <bits/stdc++.h>
using namespace std;

string nextWord(string s)
{
	// If string is empty.
	if (s == "")
		return "a";

	// Find first character from right 
	// which is not z.
	
	int i = s.length() - 1;
	while (s[i] == 'z' && i >= 0)
		i--;

	// If all characters are 'z', append
	// an 'a' at the end.
	if (i == -1) 
		s = s + 'a';

	// If there are some non-z characters 
	else
		s[i]++;

	return s; 
}

// Driver code
int main()
{
	string str = "samez";
	cout << nextWord(str);
	return 0;
}
