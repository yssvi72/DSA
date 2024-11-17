class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int res = INT_MAX;  // We want to find the smallest length, start with the largest possible number.
        long long curSum = 0;  // This will track the running sum.
        deque<pair<long long, int>> q;  // This will help us keep track of previous sums.

        // Go through the array, one element at a time.
        for (int r = 0; r < nums.size(); r++) {
            curSum += nums[r];  // Add the current number to the running sum.

            // If the current sum is already enough, update the result.
            if (curSum >= k) {
                res = min(res, r + 1);  // The length of this subarray is (r + 1).
            }

            // Check if we can find a subarray with sum >= k by subtracting a previous sum.
            while (!q.empty() && curSum - q.front().first >= k) {
                auto [prefix, endIdx] = q.front();  // Take the front sum from the deque.
                q.pop_front();  // Remove it from the deque.
                res = min(res, r - endIdx);  // Calculate the length of the subarray.
            }

            // Make sure the deque only has useful sums (we want smaller sums earlier).
            while (!q.empty() && q.back().first > curSum) {
                q.pop_back();  // Remove sums that are bigger than the current sum.
            }

            // Add the current sum to the deque.
            q.push_back({curSum, r});
        }

        // If we found a valid subarray, return its length. Otherwise, return -1.
        return res == INT_MAX ? -1 : res;
    }
};
