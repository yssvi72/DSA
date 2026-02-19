class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 1;
        for (int modVal = 0; modVal < k; ++modVal) {
            unordered_map<int, int> dp;
            int maxLen = 0;

            for (int num : nums) {
                int need = (modVal - (num % k) + k) % k;
                int len = dp[need] + 1;
                dp[num % k] = max(dp[num % k], len);
                maxLen = max(maxLen, len);
            }

            result = max(result, maxLen);
        }

        return result;
    }
};
