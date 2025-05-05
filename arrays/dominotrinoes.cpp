class Solution {
public:
    int numTilings(int n) {
        // dp[i] = number of tilings till size i

/** dp[i]   = dp[i - 1]       +        dp[i - 2]          + 2 [\sum_{j = 0}^{i - 3} dp[j]
          (end with vertical)   (end with two horizontal)     (trominoes at end)
            */
// can use prefix sums, but on simplification, relation becomes
// dp[i] = 2 * dp[i - 1] + dp[i - 3]
        long long MODULO = 1e9 + 7;

        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else if (n == 3) {
            return 5;
        }
        vector<long long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MODULO; 
        }
        return (int) dp[n];
    }
};
