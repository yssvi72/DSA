class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        // notSpecial array with all elements equal to 0
        vector<int> notSpecial(n, 0);

        // When you find a pair of elements that are both even or odd, the value of notSpecial array increases by 1
        // If it is a notSpecial array, the first and last values ​​will be different
        for (int i = 1; i < n; i++) {
            notSpecial[i] = notSpecial[i - 1];
            if ((nums[i] % 2 == nums[i - 1] % 2)) {
                notSpecial[i]++;
            }
        }

        // Go through each sub-array to see which array has the first and last elements having equal or unequal values
        vector<bool> ans;
        for (const auto& query : queries) {
            int idxS = query[0], idxE = query[1];
            int nonSpecialCount = notSpecial[idxE] - notSpecial[idxS];
            ans.push_back(nonSpecialCount == 0);
        }

        return ans;
    }
};
