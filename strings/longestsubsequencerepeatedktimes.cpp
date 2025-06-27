class Solution {
    int k_copy;
    string s_copy;
    unordered_map<char,int>mp;
    string ans="";
public:
    bool ksubseq(string &temp)
    {
        string check="";
        for(int i=0;i<k_copy;i++)
        {
            check+=temp;
        }
        int j=0;
        for(char c:s_copy)
        {
            if(check[j]==c) {
                j++;
            }
            if(j==check.size()) return true;
        }
        return false;
    }
    // void backtrack(string &temp, string &candidates, int max_len)
    // {
    //     if(temp.size()>max_len) return;
    //     if(temp.size()>ans.size() || (temp.size()==ans.size() && temp>ans) )
    //     {
    //         if(ksubseq(temp))
    //         {
    //             ans=temp;
    //         }
    //     }
        
    //     for(char c:candidates)
    //     {
    //         temp.push_back(c);
    //         backtrack(temp,candidates,max_len);
    //         temp.pop_back();     
    //     }
    
    // }
    string longestSubsequenceRepeatedK(string s, int k) {
        s_copy=s;
        k_copy=k;
        int n=s.size();
        for(char c:s) mp[c]++;

        string candidates="";
        for(char c='z';c>='a';c--)
        {
            if(mp[c]>=k)
            {
                candidates+=c;
            }
        }

        queue<string> q;
        q.push("");

        string best = "";
        int maxLen = n / k;

        while (!q.empty()) {
            string curr = q.front(); q.pop();
            for (char c : candidates) {
                string next = curr + c;
                if (next.size() > maxLen) continue;

                if (ksubseq(next)) {
                    q.push(next);
                    if (next.size() > best.size() || (next.size() == best.size() && next > best)) {
                        best = next;
                    }
                }
            }
        }

        return best;

        // string temp="";
        // backtrack(temp,candidates,n/k);
        // return ans;
    }
};
