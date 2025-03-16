class Solution {
public:
    bool check(vector<int>& nums, long long mid, int cars) {
        long long cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt += (long long)sqrt(mid/nums[i]);
        }
        return cnt >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1LL * *max_element(ranks.begin(), ranks.end()) * cars * cars;
        long long ans = -1;
        while(l <= r) {
            long long mid = (l+r)>>1;
            if(check(ranks, mid, cars)) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};
