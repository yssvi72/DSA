class Solution {
public:

    const long long mod = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int num=1;
        vector<int> powers;
        for (int i = 0; n > 0; i++) {
            if (n & 1) {
                powers.push_back(1 << i);
            }
            n >>= 1;
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int min=queries[i][0];
            int max=queries[i][1];
            long ans_num=1;
            for(int j=min;j<=max;j++){
                ans_num=(ans_num*powers[j])%mod;
            }
            ans.push_back(ans_num);
        }
        return ans;
    }
};
