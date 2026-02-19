/*
    Use of Array<> version
 */
class Solution {
private:
    const static int ALP_LEN   = 26;
    const static int MOD       = 1e9+7;
    using LL = long long;
    using MATR_LL = array<array<LL, ALP_LEN>, ALP_LEN>;
    MATR_LL matrMul(const MATR_LL& A, const MATR_LL& B) {
        MATR_LL res = {};
        for (int i = 0; i < ALP_LEN; ++i) { // row size of A
            for (int j = 0; j < ALP_LEN; ++j) { // col size of B
                for (int k = 0; k < ALP_LEN; ++k) { // col size of A
                    res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    MATR_LL matIdentity() {
        MATR_LL I = {};
        for (int i = 0; i < ALP_LEN; ++i) I[i][i] = 1;
        return I;
    }

    MATR_LL matPow(MATR_LL& A, int exp) {
        MATR_LL res = matIdentity();
        while (exp > 0) {
            if (exp & 1) res = matrMul(res, A);
            A = matrMul(A, A);
            exp /= 2;
        }
        return res;
    }

    vector<LL> simulateSmallT(vector<LL>& freq, const vector<int>& nums, int t) {
        for (int step = 0; step < t; ++step) {
            vector<LL> next(ALP_LEN, 0);
            for (int i = 0; i < ALP_LEN; ++i) {
                for (int j = 1; j <= nums[i]; ++j) {
                    int shift = (i + j) % ALP_LEN;
                    next[shift] = (next[shift] + freq[i]) % MOD;
                }
            }
            freq = next;
        }
        return freq;
    }
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int ans = 0;
        vector<LL> freq(ALP_LEN, 0);
        for (char c:s) ++freq[c-'a'];
        // Optimization: simulate when t is small
        if (t < 500) {
            freq = simulateSmallT(freq, nums, t);
            LL ans = 0;
            for (LL val : freq) ans = (ans + val) % MOD;
            return ans;
        }

        MATR_LL T = {};
        // T[to][from]
        for (int i = 0; i < ALP_LEN; ++i) {
            for (int j = 1; j <= nums[i]; ++j) T[(i+j) % ALP_LEN][i] = 1;
        }

        MATR_LL transform = matPow(T, t);
        for (int i = 0; i < ALP_LEN; ++i) {
            for (int j = 0; j < ALP_LEN; ++j) {
                ans = (ans + transform[i][j] * freq[j]) % MOD;
            }
        }

        return ans;
    }
};
