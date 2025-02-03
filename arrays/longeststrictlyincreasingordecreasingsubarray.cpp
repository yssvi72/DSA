class Solution {
public:
    int solve(vector<int>& nums) {
        int max_value = 0;
        for(int i = 0; i < nums.size(); i++) {
            int len = 1, j = i + 1;
            while(j < nums.size() && nums[j] > nums[j-1]) j++;
            max_value = max(max_value, j - i);
        }
        return max_value;
    }

    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = solve(nums);  // Check for increasing subarray
        reverse(nums.begin(), nums.end());  // Reverse to check for decreasing subarray
        ans = max(ans, solve(nums));  // Get the maximum of both cases
        return ans;
    }
};
