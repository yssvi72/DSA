class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i <= n - 3; ++i) {
            if (nums[i] == 0) {
                // Flip nums[i], nums[i + 1], nums[i + 2]
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                count++;
            }
        }
        
        // If any element remains 0, return -1
        for (int num : nums) {
            if (num == 0) return -1;
        }
        
        return count;
    }
};
