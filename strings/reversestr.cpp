// C++ program to reverse a string 
// Using recursion
#include <bits/stdc++.h>
using namespace std;

// Function to reverse a string
void reverseStr(string& str, int n, int i)
{
	
if(n<=i){return;}
// Swapping the character 
swap(str[i],str[n]);
reverseStr(str,n-1,i+1);

}

//Inbuilt reverse:
// reverse() function
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str = "geeksforgeeks";

	// Reverse str[begin..end]
	reverse(str.begin(), str.end());

	cout << str;
	return 0;
}

//Constructor
// C++ program to reverse
// string using constructor
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str = "GeeksforGeeks";

	// Use of reverse iterators
	string rev = string(str.rbegin(), str.rend());

	cout << rev << endl;
	return 0;
}

//Temporary string
// C++ program to demonstrate
// reversing of string 
// using temporary string
#include <bits/stdc++.h>
using namespace std;
int main()
{

	string str = "GeeksforGeeks";
	int n = str.length();

	// Temporary string to store the reverse
	string rev;

	for (int i = n - 1; i >= 0; i--)
		rev.push_back(str[i]);

	cout << rev << endl;
	return 0;
}



