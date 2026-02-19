class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>freq;
        int cnt = 0;
        if(s.size()<k)
        {
            return false;
        }
        
        for(int i=0;i<s.size();i++)
            {
                freq[s[i]]++;
            }
        for(auto i:freq )
        {
            if((i.second)%2!=0)
            {
                cnt++;
            }
            if(cnt>k)
            {
                return false;
            }
        }
        return true;
    }
};
