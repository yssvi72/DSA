class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxi = 0; // maximum sum
        long long sum = 0;  // current sum

        // maintain the frequency of each elements in the arrays
        // um, for a larger range of values could be replaced by an unordered_map
        // **the stack allocated array will be faster than the heap allocated unordered_map
        int um[(int)(1e5 + 1)] = {0};   
        
        int overCount = 0;  // the amount of of copies over in the subarray --> maintain this instead of checking all of the frequency arrays

        // find the sum of the first k elements
        for(int i = 0; i < k; i++) {
            um[nums[i]]++;
            if(um[nums[i]] > 1) {   // if we have more than one copy, we increase the amount of overCopies by 1
                overCount++;
            }
            sum += nums[i];
        }

        if(overCount == 0) {    // we update the maximum only if we have a subarray with distinct elements
            maxi = max(maxi, sum);
        }

        // slide the windows of k elemenets, by one element to the right, until the end of array
        for(int i = k; i < nums.size(); i++) {
            um[nums[i-k]]--;
            sum -= nums[i-k];
            if(um[nums[i-k]] >= 1) {   // if we eliminated an element, and still have at least one appearence -> we eliminated a copy -> decrease the overCount
                overCount--;
            }

            um[nums[i]]++;
            sum += nums[i];
            if(um[nums[i]] > 1) {
                overCount++;
            }
            if(overCount == 0) {
                maxi = max(maxi, sum);
            }
        }
  
        return maxi;
    }
};
