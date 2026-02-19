class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int cnt = 0;
        for(int i = 0;i < s.size();++i){
            if(s[i] == '1') cnt++;
            else{
                ans += cnt;
                swap(s[i],s[i-cnt]);
            }
        }
        return ans;
    }
};
