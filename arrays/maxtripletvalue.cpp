class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
         int n = nums.size();
        long long max_value = 0;

        // Step 1: Precompute max_i[j] which stores the max nums[i] for i < j
        vector<int> max_i(n, 0);
        max_i[0] = nums[0];

        for (int j = 1; j < n; j++) {
            max_i[j] = max(max_i[j - 1], nums[j - 1]);
        }

        // Step 2: Iterate over (j, k) pairs
        for (int j = 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (max_i[j] > nums[j]) { // Ensure valid (nums[i] - nums[j])
                    long long value = (long long)(max_i[j] - nums[j]) * nums[k];
                    max_value = max(max_value, value);
                }
            }
        }

        return max_value;
    }
};
