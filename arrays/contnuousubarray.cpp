class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        nums.push_back(-2), ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        long n = nums.size(), lo = 0, hi = 1, ret = 0, y, a, b, x, mxI, found, i;
        for (vector<vector<long>> v(1, {nums[0], 0}); hi < n; hi++) {
            for (x = nums[hi], found = 0; vector<long>& V : v) if (V[0] == x) V[1] = hi, found = 1;
            if (found) continue; else for (mxI = -1; vector<long>& V : v) if (V[0] - x > 2 || x - V[0] > 2) mxI = max(mxI, V[1]);
            if (++mxI) for (i = -1, a = lo, y = mxI - a, b = mxI, a *= (a - 1), b *= (b - 1), ret += y * hi + a / 2 - b / 2, lo = mxI; ++i < size(v);) if (v[i][1] < lo) v.erase(begin(v) + i--);
            v.push_back({x, hi});
        }
        return ret;
    }
};
