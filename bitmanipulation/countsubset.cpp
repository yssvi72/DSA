class Solution {
public:
    int countSubsets(int ind, int currOr, vector<int>& nums, int maxOr, vector<vector<int>> &t) {
        // base case 
        if (ind == nums.size()) {
            return (currOr == maxOr) ? 1 : 0;
        }

        // return if already calculated
        if (t[ind][currOr] != -1) {
            return t[ind][currOr];
        }

        // take nums[ind]
        int takeCount = countSubsets(ind + 1, currOr | nums[ind], nums, maxOr, t);

        // not taking nums[ind]
        int notTakeCount = countSubsets(ind + 1, currOr, nums, maxOr, t);

        // memoize result
        return t[ind][currOr] = takeCount + notTakeCount;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int &num : nums) {
            maxOr |= num; 
        }

        int n = nums.size();
        vector<vector<int>> t(n + 1, vector<int>(maxOr + 1, -1));
        
        return countSubsets(0, 0, nums, maxOr, t);
    }
};
