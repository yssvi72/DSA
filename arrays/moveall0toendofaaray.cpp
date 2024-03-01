/*Given an array of random numbers, Push all the zero’s of a given array to the end of the array. 
For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. 
The order of all other elements should be same. Expected time complexity is O(n) and extra space is O(1).
Example: 
Input :  arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0};
*/

#include <algorithm> 
#include <iostream> 
#include <vector> 

void push_zeros_to_end(std::vector<int>& arr) 
{ 
std::stable_partition(arr.begin(), 
			arr.end(), 
			[](int n) { return n != 0; }); 
} 

int main() 
{ 
std::vector<int> arr{1,9,8,4,0,0,2,7,0,6,0,9}; 
	
push_zeros_to_end(arr); 
	
for(const auto& i : arr) 
	std::cout << i << ' '; 

std::cout << "\n"; 

return 0; 
}  
//T-O(n) ,S-O(1)

//Method 2: Partitioning the array------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Approach: The approach is pretty simple. We will use 0 as a pivot element and whenever we see a non zero element we will swap it with the pivot element. So all the non zero element will come at the beginning.
// C++ Program to move all zeros to the end 

#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 
	int A[] = { 5, 6, 0, 4, 6, 0, 9, 0, 8 }; 
	int n = sizeof(A) / sizeof(A[0]); 
	int j = 0; 
	for (int i = 0; i < n; i++) { 
		if (A[i] != 0) { 
			swap(A[j], A[i]); // Partitioning the array 
			j++; 
		} 
	} 
	for (int i = 0; i < n; i++) { 
		cout << A[i] << " "; // Print the array 
	} 

	return 0; 
}
//Method 3: using C++ STL-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*In this approach, we will traverse the whole array and will count the number of zeros present in the array. While counting we will delete the zero from the array.
After completing the above process, we will push back the count number of zeros into the array.*/
// C++ program to shift all zeros 
// to right most side of array 
// without affecting order of non-zero 
// elements. 

#include <bits/stdc++.h> 
using namespace std; 
// function to shift zeros 
void move_zeros_to_right(vector<int>& m) 
{ 
	int count = 0; 
	int length=m.size(); 
	for (int i = 0; i < length; i++) { 
		if (m[i] == 0) { 
			count++; 
			// deleting the element from vector 
			m.erase(m.begin() + i); 
			i--; 
			// The length gets decresed after erasing each element 
			length--; 
		} 
	} 

	for (int i = 0; i < count; i++) { 
		// inserting the zero into vector 
		m.push_back(0); 
	} 
	cout << "array after shifting zeros to right side: "
		<< endl; 
	for (int i = 0; i < m.size(); i++) { 
		// printing desired vector 
		cout << m[i] << " "; 
	} 
} 
// driver code 
int main() 
{ 
	vector<int> m{ 5, 6, 0, 4, 6, 0, 9, 0, 8 }; 
	// function call 
	move_zeros_to_right(m); 
	return 0; 
} 

//Method-4: using extra space----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//In this approach, we will take an array of the same size as the input array and run a for loop on the input array. 
//In that for loop, if the element does not equal 0, then place that element in the new array and if that element is 0 increase the count of 0. 
//Then add as many 0 In that new array as we have the count of zeroes. Then copy elements of this new array into our old/input array.
// C++ Program to move all zeros to the end 

#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 
	int A[] = { 5, 6, 0, 4, 6, 0, 9, 0, 8 }; 
	int n = sizeof(A) / sizeof(A[0]); 
	int B[n]; 
	int j = 0; 
	int count = 0; 
	for (int i = 0; i < n; i++) { 
		if (A[i] != 0) { 
			B[j] = A[i]; 
			j++; 
		} 
		else { 
			count++; 
		} 
	} 
	while (count > 0) { 
		B[j] = 0; 
		count--; 
		j++; 
	} 

	for (int i = 0; i < n; i++) { 
		A[i] = B[i]; 
	} 

	for (int i = 0; i < n; i++) { 
		cout << A[i] << " "; // Print the array 
	} 

	return 0; 
}
//TC-O(N) , SC-O(N)
