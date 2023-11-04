                                          # Remove Duplicates from Sorted Array
Removing duplicate is a tedious task if the array is unsorted but it becomes a cakewalk if the array is already sorted:

      Intution:
      If the array is already sorted , the two consecutive position will have its duplicates 
      For eg: arr1[]={ 4,1,4,3,5,6,9,2}
      If we sort the arr1 we get={ 1,2,3,4,4,5,6,9} , now by looking at this we can say that 4 is repeated twice so delete it. 
      Expected Output:-Replace duplicate element with next number

1. Naive Approach  [Time Complexity ------> O(n^2) ] 
      Program :
      class Solution {
      public:
      int removeDuplicates(vector<int>& nums) {
        int currIndex=1;      // Keeps a track of position where unique element shall be placed
        for(int i=1;i<nums.size();i++)
        {   //Iterate through entire array till we reach last element
            if(nums[i]!=nums[i-1])           
            { //Check current and previous element if they are not same there  arent any duplicate for element
            nums[currIndex]=nums[i];  //CurrentIndex should be ith position  
            currIndex++; // Move forward 
            }
        }
      return currIndex;
      }
};     

2. 



       
