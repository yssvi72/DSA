class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& w) {
        int c=0;
        int n=w.size();
        for(int i=0;i<n;i++)
        {
            int t=w[i].size();
            for(int j=i+1;j<n;j++)
            {
               int x=w[j].size();
               if(w[i].size()>x)continue;
               if(w[i]==w[j].substr(0,t) && w[i]==w[j].substr(x-t))c++;
            }
        }
        return c;
    }
};
