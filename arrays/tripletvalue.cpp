class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0, maxDiff = 0;
        int maxx = 0;
        for (int x : nums) {
            ans = max(ans, maxDiff * x);
            maxDiff = max(maxDiff, 1LL * maxx - x);
            maxx = max(maxx, x);
        }
        return ans;
    }
};
