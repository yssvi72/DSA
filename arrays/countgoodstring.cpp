class Solution {
public:
    #define mod 1000000007
    int solve(int good,int low,int high,int zero,int one,vector<int>&dp){
        if(good>high) return 0;
        if(dp[good] != -1) return dp[good];
        int zstr = 0,onestr = 0;
        onestr = solve(good+one,low,high,zero,one,dp);
        zstr = solve(good+zero,low,high,zero,one,dp);
        if(good>=low && good<=high) return dp[good] = (1 + onestr + zstr) % mod;
        return dp[good] = (onestr + zstr) % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int good = 0;
        vector<int>dp(high+1,-1);
        int ans = solve(good,low,high,zero,one,dp);
        return ans%mod;
    }
};
