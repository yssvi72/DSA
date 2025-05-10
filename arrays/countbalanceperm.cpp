class Solution {
    const int MOD = 1e9+7;
    vector<long long> fact, inv, invFact;
public:
    int countBalancedPermutations(string num) {
        int n = num.size(), sum = 0;
        for (const char& c : num)
            sum += c - '0';
        if (sum % 2 == 1)
            return 0;
        preCalculate(n);
        int halfSum = sum / 2, halfLen = n / 2;
        vector<vector<int>> dp(halfSum + 1, vector<int>(halfLen + 1));
        dp[0][0] = 1;
        vector<int> digits(10);
        for (const char& c : num) {
            int digit = c - '0';
            digits[digit]++;
            for (int i = halfSum; i >= digit; i--)
                for (int j = halfLen; j > 0; j--)
                    dp[i][j] = (dp[i][j] + dp[i - digit][j - 1]) % MOD;
        }
        long long res = dp[halfSum][halfLen];
        res = res * fact[halfLen] % MOD * fact[n - halfLen] % MOD;
        for (int i : digits)
            res = res * invFact[i] % MOD;
        return res;
    }
    
    void preCalculate(int n) {
        fact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) // Factorials.
            fact[i] = fact[i - 1] * i % MOD;
        inv.assign(n + 1, 1);
        for (int i = 2; i <= n; i++) // Inverses.
            inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
        invFact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) // Factorial inverses.
            invFact[i] = invFact[i - 1] * inv[i] % MOD;
    }
};
