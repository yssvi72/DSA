class Solution {
private:
    const static int MOD = 1e9 + 7;
    
    // static = maintains state across multiple calls
    static vector<int> pows;        //this is pre-computed
    static bool preComputed;        // this tells its pre-computed

    static void preCompute() {      
        pows[0] = 1;
        for (int i = 1; i < pows.size(); ++i) {
            pows[i] = (pows[i - 1] * 2LL) % MOD;
        }
        preComputed = true;
    }

public:
    int numSubseq(vector<int>& nums, int target) {
        if (!preComputed) preCompute();

        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int ans = 0;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + pows[r - l]) % MOD;
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};

vector<int> Solution::pows(1e5 + 1);    // that's how we set static variables. 
// Outside the class
bool Solution::preComputed = false;
