//Input: arr1[] = { 1, 3, 4, 5}, arr2[] = {2, 4, 6, 8} 
//Output: arr3[] = {1, 2, 3, 4, 4, 5, 6, 8}

//1.Naive Approach:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//It is the brute force method to do the same. Take all the elements of arr1 and arr2 in arr3. Then simply sort the arr3.
// C++ program to merge two sorted arrays/
#include<bits/stdc++.h>
using namespace std;

void mergeArrays(int arr1[], int arr2[], int n1,
							int n2, int arr3[])
{
	int i = 0, j = 0, k = 0;
	// traverse the arr1 and insert its element in arr3
	while(i < n1){
	arr3[k++] = arr1[i++];
	}
	
	// now traverse arr2 and insert in arr3
	while(j < n2){
	arr3[k++] = arr2[j++];
	}
	
	// sort the whole array arr3
	sort(arr3, arr3+n1+n2);
}

// Driver code
int main()
{
	int arr1[] = {1, 3, 5, 7};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);

	int arr2[] = {2, 4, 6, 8};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	int arr3[n1+n2];
	mergeArrays(arr1, arr2, n1, n2, arr3);

	cout << "Array after merging" <<endl;
	for (int i=0; i < n1+n2; i++)
		cout << arr3[i] << " ";

	return 0;
} //Time Complexity : O((m+n) log(m+n)) , the whole size of arr3 is m+n , Auxiliary Space: O(m+n), where m is the size of arr1 and n is the size of arr2.----------------------------------------------------------------------------------------

//2. Method 2: Merge sort
//The idea is to use Merge function of Merge sort. 
//1.Create an array arr3[] of size n1 + n2.
//2.Simultaneously traverse arr1[] and arr2[]. 
//3.Pick smaller of current elements in arr1[] and arr2[], copy this smaller element to next position in arr3[] and move ahead in arr3[] and the array whose element is picked.
//4.If there are remaining elements in arr1[] or arr2[], copy them also in arr3[].
// Merge arr1[0..n1-1] and arr2[0..n2-1] into
// arr3[0..n1+n2-1]
void mergeArrays(int arr1[], int arr2[], int n1,
                             int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
 
    // Traverse both array
    while (i<n1 && j <n2)
    {
        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
 
    // Store remaining elements of first array
    while (i < n1)
        arr3[k++] = arr1[i++];
 
    // Store remaining elements of second array
    while (j < n2)
        arr3[k++] = arr2[j++];
} // Time Complexity : O(n1 + n2)  , Auxiliary Space : O(n1 + n2)------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//3. Method 3: Using Maps (O(nlog(n) + mlog(m)) Time and O(N) Extra Space) 
void mergeArrays(int a[], int b[], int n, int m) 
{
    // Declaring a map.
    // using map as a inbuilt tool
    // to store elements in sorted order.
    map<int, int> mp;
     
    // Inserting values to a map.
    for(int i = 0; i < n; i++)mp[a[i]]++;
     
     
    for(int i = 0;i < m;i++)mp[b[i]]++;
 
     
    // Printing keys of the map.
    for(auto j: mp)
    {
         for(int i=0; i<j.second;i++)cout<<j.first<<" ";
    }
}//Time Complexity: O( nlog(n) + mlog(m) ) , Auxiliary Space: O(N)-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
