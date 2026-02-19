class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        vector<int> res_g;
        int n = words.size();
        vector<int> dp(n, 1);
        int k = 1;
        auto GetDist = [](string& a, string& b) {
            int dist = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) dist++;
            }
            return dist;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (words[i].length() != words[j].length()) continue;
                if (GetDist(words[i], words[j]) != 1) continue;
                if (groups[i] == groups[j]) continue;
                dp[i] = max(dp[i], dp[j] + 1);
            }
            k = max(k, dp[i]);
        }
        int len = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] == k) {
                if (res.empty() || (words[i].length() == len && GetDist(words[i], res.back()) == 1 && groups[i] != res_g.back())) {
                    res.push_back(words[i]);
                    res_g.push_back(groups[i]);
                    k--;
                    len = words[i].length();
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
