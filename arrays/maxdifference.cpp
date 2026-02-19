class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size(), ans = INT_MIN;
        vector<int> cntA(n + 1), cntB(n + 1);

        for (char chA = '0'; chA <= '4'; ++chA) {
            for (char chB = '0'; chB <= '4'; ++chB) {
                if (chA == chB) continue;

                for (int i = 0; i < n; ++i) {
                    cntA[i + 1] = cntA[i] + (s[i] == chA);
                    cntB[i + 1] = cntB[i] + (s[i] == chB);
                }

                int bestDiff[2][2] = {{INT_MIN, INT_MIN}, {INT_MIN, INT_MIN}};
                int l = 1;

                for (int r = k; r <= n; ++r) {
                    while (r - l + 1 >= k && cntA[r] > cntA[l - 1] && cntB[r] > cntB[l - 1]) {
                        int parityA = cntA[l - 1] % 2;
                        int parityB = cntB[l - 1] % 2;
                        bestDiff[parityA][parityB] = max(bestDiff[parityA][parityB], cntB[l - 1] - cntA[l - 1]);
                        ++l;
                    }
                    int parityA = cntA[r] % 2;
                    int parityB = cntB[r] % 2;
                    int diff = bestDiff[parityA ^ 1][parityB ^ 0]; // a must be odd, b must be even
                    if (diff != INT_MIN)
                        ans = max(ans, cntA[r] - cntB[r] + diff);
                }
            }
        }

        return ans == INT_MIN ? -1 : ans;
    }
};
