class Solution {
public:
    static bool cmp(string& s1, string& s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();
        int f1 = 0, f2 = 0;

        for(int i = 0; i < l1; i++)
        {
            if(s1[i] == '/') f1++;
        }
        for(int i = 0; i < l2; i++)
        {
            if(s2[i] == '/') f2++;
        }
        
        return f1 < f2;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), cmp);

        vector<string> ans;
        unordered_map<string, int> mp;
        for(auto& x: folder)
        {
            int f = 0;
            string s = "";
            int l = x.length();
            for(int i = 0; i < l; i++)
            {
                if(x[i] == '/')
                {
                    s = s + x[i];
                }
                else
                {
                    s = s + x[i];
                    if(i+1 < l)
                    {
                        if(mp[s] && x[i+1] == '/')
                        {
                            f = 1;
                            break;
                        }
                    }
                    else
                    {
                        if(mp[s])
                        {
                            f = 1;
                            break;
                        }
                    }    
                }
            }
            if(!f)
            {
                mp[x]++;
                ans.push_back(x);
            }
        }
        return ans;
    }
};
