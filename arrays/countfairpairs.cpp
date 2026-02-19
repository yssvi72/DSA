class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();
        
        sort(nums.begin() , nums.end());

        for(int i=0 ; i<n-1 ; i++){
            int first = lower-nums[i] , last = upper-nums[i];
            auto left = lower_bound(nums.begin()+i+1 , nums.end() , first); // lower_bound returns the first element index which is equal to passed argument or greater than that.
            auto right = upper_bound(nums.begin()+i+1 , nums.end() , last); // upper_bound returns the first element index which is greater then the passed argument.
            ans += right-left;
        }
        return ans;
    }
};
