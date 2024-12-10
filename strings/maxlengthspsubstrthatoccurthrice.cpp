class Solution {
public:
    int maximumLength(string s) {
        int cnt[26][51]; 
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 51; j++)
                cnt[i][j] = 0; 
        }
        int l = 0, r;
        for(r = 1; r < s.size(); r++) {
            if(s[r] != s[r - 1]) {
                cnt[s[r - 1] - 'a'][r - l]++; 
                for(int i = 1; i < r - l; i++) 
                    cnt[s[r - 1] - 'a'][i] += r - l - i + 1;
                l = r;
            }
        }
        cnt[s[r - 1] - 'a'][r - l]++; 
        for(int i = 1; i < r - l; i++) 
            cnt[s[r - 1] - 'a'][i] += r - l - i + 1;
        int res = -1; 
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 51; j++) {
                if(cnt[i][j] >= 3)
                    res = max(res, j);
            }
        }
        return res;
    }
};
