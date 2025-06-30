class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int ans = 0;
        for (auto& [num, count] : freq) {
            if (freq.count(num + 1)) {
                ans = max(ans, count + freq[num + 1]);
            }
        }
        return ans;
    }
};
