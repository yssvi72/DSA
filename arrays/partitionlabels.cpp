class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,pair<int,int>>mp;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            if(mp.find(c)==mp.end())
            {
                mp[c]={i,i};
            }
            else
            {
                mp[c].second=i;
            }
        }
        vector<pair<int,int>>pairs;
        for(auto num:mp)
        {
            pairs.push_back(num.second);
        }
        sort(pairs.begin(),pairs.end());
        vector<int>ans;
        int start=pairs[0].first;
        int end=pairs[0].second;
        for(int i=1;i<pairs.size();i++)
        {
            if(pairs[i].first<=end)
            {
                end=max(end,pairs[i].second);
            }
            else
            {
                ans.push_back(end-start+1);
                start=pairs[i].first;
                end=pairs[i].second;
            }
        }
        ans.push_back(end-start+1);
        return ans;

    }
};
