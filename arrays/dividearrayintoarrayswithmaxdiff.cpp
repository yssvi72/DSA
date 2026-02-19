class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Edge case: total elements must be divisible by 3
        if (n % 3 != 0) return {};

        vector<vector<int>> res;
        sort(begin(nums), end(nums));

        for (int i = 0; i < n; i += 3) {
            // Check that the triplet is valid
            if ((nums[i + 2] - nums[i]) > k) {
                return {};
            }
            res.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }

        return res;
    }
};
