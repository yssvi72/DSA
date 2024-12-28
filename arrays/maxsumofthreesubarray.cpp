class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int size = nums.size();
        // dp[length][n] = maxSum
        // up to the length of nums array, what is the max sum when n windows are picked
        int dp[size + 1][4];
        memset(dp, 0, sizeof(dp));
        // sum the first k numbers as the initial window
        int windowSum = accumulate(nums.begin(), nums.begin() + k, 0);
        dp[k][1] = windowSum;
        for (int i = k; i < size; i++) {
            // update the window sum
            windowSum += nums[i] - nums[i - k];
            for (int nWindowsPicked = 1; nWindowsPicked <= 3; nWindowsPicked++) {
                // We can either choose to skip the current window: dp[i][nWinowsPicked],
                // or take the current window: dp[i + 1 - k][nWinowsPicked - 1] + windowSum
                // Some dp values are invalid when i < 3 * k - 1,
                // but the final result will be valid as long as the length of the nums array is sufficient
                // Alternatively, we may put nWindowsPicked to the outer loop to avoid filling
                // these invalid dp values, at the cost of more windowSum calculations
                dp[i + 1][nWindowsPicked] = max(dp[i][nWindowsPicked], dp[i + 1 - k][nWindowsPicked - 1] + windowSum);
            }
        }
        vector<int> res(3, 0);
        int pos = size, nWindow = 3;
        while (nWindow) {
            if (dp[pos - 1][nWindow] == dp[pos][nWindow]) {
                // if the maxSum doesn't change without the current window, we skip the current num
                --pos;
            } else {
                // otherwise, we take the current window
                res[--nWindow] = pos - k;
                // and skip the length of the whole window
                pos -= k;
            }
        }
        return res;
    }
};
