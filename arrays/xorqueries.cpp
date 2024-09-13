class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // Idea is that (a ^ b) ^ b --> a so we can have prefix sum

        vector<int> prefix = {0};
        int n = arr.size();
        for (int i = 0; i < n; i++) prefix.push_back(prefix.back() ^ arr[i]);
        vector<int> ans;
        for (auto &q : queries) {
            ans.push_back(prefix[q[0]] ^ prefix[q[1] + 1]);
        }
        return ans;
    }
};
