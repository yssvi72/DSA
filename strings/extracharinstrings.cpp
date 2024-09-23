class Solution {
public:
    int v[51];
    int solve (int i, string& s, unordered_set<string>& st, int n) {
        if(i>= n) {
           return 0;
        }

        if(v[i] != -1) {
                return v[i];
            }
        int result = 1+ solve(i+1,s,st,n);
        for(int j=i; j<n; j++) {
            string curr = s.substr(i, j-i+1);
            if (st.count(curr)) {
                result = min(result, solve(j+1,s,st,n));
            }
        }
        return v[i] = result;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        memset (v, -1, sizeof(v));
        unordered_set<string> st(begin(dictionary), end(dictionary));
        return solve(0,s,st,n);
        
    }
};
