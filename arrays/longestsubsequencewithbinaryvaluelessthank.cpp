class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int len = 0;
        int power = 0;
    
        int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                len++;
            } else if (power < 32 && (sum + (1LL << power) <= k)) {
                sum+=1LL<<power;
                len++;
            }
            power++;
        }
        return len;
    }
};
