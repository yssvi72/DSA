class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum % 2 != 0) {
            return false;
        }
        int target = sum/2;
        vector<bool> dp(target+1,false);
        dp[0] = true;

        for(auto& element : nums){
            for(int i = target;i>element - 1;i--){
                dp[i] = dp[i] || dp[i - element];
            }
        }

        return dp[target];
    }
};
