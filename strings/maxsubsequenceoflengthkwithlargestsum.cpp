class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++)
            v.emplace_back(nums[i], i);
        sort(v.begin(), v.end(),
             [](auto& a, auto& b) { return a.first > b.first; }); // 由大到小

        vector<pair<int, int>> vv(v.begin(), v.begin() + k);

        sort(vv.begin(), vv.end(),
             [](auto& a, auto& b) { return a.second < b.second; });

        vector<int> ans;
        for (const auto& i : vv) ans.push_back(i.first);
        return ans;
    }
};
