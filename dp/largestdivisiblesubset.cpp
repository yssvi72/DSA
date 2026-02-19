class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int>dp(n, 1), prev(n, -1);
        vector<int>ans;
        int maxi=1, l=0;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j] == 0 && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                l = i;
            }
        }

        for(int i=l; i!=-1; i=prev[i]){
            ans.push_back(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
