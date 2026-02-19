class Solution {
public:
    double soupServings(int n) {
        if (n > 4800) return 1.0; // For large n, probability approaches 1
        int m = (n + 24) / 25;    // Convert ml to units of 25 ml servings
        vector<vector<double>> dp(m + 1, vector<double>(m + 1, 0.0));

        function<double(int, int)> dfs = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5; // Both empty
            if (a <= 0) return 1.0;           // A empty first
            if (b <= 0) return 0.0;           // B empty first
            if (dp[a][b] > 0) return dp[a][b];

            dp[a][b] = 0.25 * (
                dfs(a - 4, b) +        // 100 ml A, 0 ml B
                dfs(a - 3, b - 1) +    // 75 ml A, 25 ml B
                dfs(a - 2, b - 2) +    // 50 ml A, 50 ml B
                dfs(a - 1, b - 3)      // 25 ml A, 75 ml B
            );
            return dp[a][b];
        };

        return dfs(m, m);
    }
};
