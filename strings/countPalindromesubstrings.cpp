class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> freq(26, {-1, -1});
        int n=s.size();

        for(int i=0; i<n; i++){
            if(freq[s[i] -'a'].first == -1) freq[s[i]-'a'].first = i;
            freq[s[i] -'a'].second = i;
        }

        int ans=0;
        for(auto it : freq){
            if(it.first==it.second || it.first==-1 || it.second==-1) continue;
            unordered_set<char> temp;
            for(int i=it.first+1; i<it.second; i++) temp.insert(s[i]);
            
            ans += temp.size();
        }

        return ans;
    }
};
