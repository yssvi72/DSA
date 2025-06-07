class Solution {
public:
    string clearStars(string &s) {
        stack<int> st[26];
        unordered_map<int, int> m;
        for(int i = 0; s[i]; i++) {
            if(s[i] == '*') {
                for(int j = 0; j < 26; j++) {
                    if(st[j].size() != 0) {
                        int k = st[j].top();
                        st[j].pop();
                        m.erase(k);
                        break;
                    }
                }
            }
            else {
                m[i]++;
                st[s[i] - 97].push(i);
            }
        }
        string ans = "";
        for(int i = 0; s[i]; i++) {
            if(m.count(i))
                ans += s[i];
        }
        return ans;
    }
};
