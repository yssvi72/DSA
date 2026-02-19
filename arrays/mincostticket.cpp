class Solution {
    int fun(vector<int>& days, vector<int>& costs, int index, vector<int>& dp) {
        if (index >= days.size()) return 0;
        if (dp[index] != -1) return dp[index];
        int a = costs[0] + fun(days, costs, lower_bound(days.begin(), days.end(), days[index] + 1) - days.begin(), dp);
        int b = costs[1] + fun(days, costs, lower_bound(days.begin(), days.end(), days[index] + 7) - days.begin(), dp);
        int c = costs[2] + fun(days, costs, lower_bound(days.begin(), days.end(), days[index] + 30) - days.begin(), dp);
        return dp[index] = min({a, b, c});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return fun(days, costs, 0, dp);
    }
};
