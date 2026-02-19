class Solution {
public:
    long long max(long long a , long long b){
        if(a > b) return a ;
        return b ;
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<long long> p(n , 0) ;
        p[0] = nums[0] ;
        vector<long long> dp(n , 0) ;
        for(int i = 1 ; i < n ; i++){
            p[i] = nums[i]+p[i-1] ; 
        }
        long long ans = p[k-1];
        dp[k-1] = ans ;
        for(int i = k ; i < n ; i++){
            long long c = p[i]-p[i-k];
            dp[i] = max(c , c+dp[i-k]) ;
            ans = max(ans , dp[i]) ;
        }
        return ans ;
    }
};
