class Solution {
public:
    int maxDistance(string s, int k) {
        map<char, int> mp;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            int res = 0;
            int n = (mp.count('N')) ? mp['N']: 0;
            int g = (mp.count('S')) ? mp['S']: 0;
            int e = (mp.count('E')) ? mp['E']: 0;
            int w = (mp.count('W')) ? mp['W']: 0;
            res += (max(n, g) + max(e, w) - min(n, g) - min(e, w));
            res += ((min(n, g) + min(e, w)) > k) ? 2*k: 2*(min(n, g) + min(e, w));
            ans = max(ans, res);
        }
        return ans;
    }
};
