class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // Step 1: Sort the nums array
        sort(nums.begin(), nums.end());
        
        // Step 2: Initialize two pointers for sliding window
        int left = 0;
        int max_len = 0;
        
        // Step 3: Iterate with the right pointer
        for (int right = 0; right < nums.size(); ++right) {
            // Ensure all elements in the window can be transformed to nums[right]
            while (nums[right] - nums[left] > 2 * k) {
                left++;
            }
            
            // Calculate the length of the current valid window
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};
