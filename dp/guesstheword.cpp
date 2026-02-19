class Solution {

    int get_matches(string &s1, string &s2)
    {
        auto cnt = 0;
        for (int i=0;i<6;i++)
        {
            if (s1[i] == s2[i])
                cnt++;
        }

        return cnt;
    }

public:
    void findSecretWord(vector<string>& words, Master& master) {
        auto n = words.size();
        vector<vector<int>> adj(n, vector<int>(n, 0));

        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                auto matches = get_matches(words[i], words[j]);
                adj[i][j] = adj[j][i] = matches;
            }
        }
        
        vector<int> curr_wt(n, 0);
        curr_wt[0] = 1;

        set<pair<int,int>> st;
        st.insert({1, 0});

        unordered_set<int> used;

        while (!st.empty())
        {
            set<pair<int,int>>::iterator it = prev(st.end());
            auto top = *it;
            st.erase(it);

            if (used.find(top.second) != used.end()) // means we already called guess on this string
                continue;

            auto match = master.guess(words[top.second]);

            used.insert(top.second);

            if (match == 6)
                break;

            // get all adj strings
            for (int i=0;i<n;i++)
            {
                if (adj[top.second][i] == match && (used.find(i) == used.end()))
                {
                    st.erase({curr_wt[i], i});
                    curr_wt[i]++;
                    st.insert({curr_wt[i], i});
                }
            }
        }
    }

    /*
    tc - O(N^2)
    sc - O(N^2)
    */
};
