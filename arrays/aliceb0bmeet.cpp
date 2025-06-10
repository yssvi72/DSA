
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        map<int, vector<pair<int, int>>> mp; // Stores index -> list of next taller buildings
        vector<pair<int, int>> st;          // Monotonic stack for next taller 
        bool flag = false;

        // Step 1: Precompute next greater elements
        for (int i = n - 1; i >= 0; --i) {
            if (st.empty() || st.back().first > heights[i]) {
                st.push_back({heights[i], i});
                flag = true;
            } else {
                while (!st.empty() && st.back().first < heights[i]) {
                    if (flag) {
                        mp[i + 1] = st;
                    }
                    flag = false;
                    st.pop_back();
                }
                st.push_back({heights[i], i});
                flag = true;
            }
        }

        // Add leftover stack to the map
        mp[0] = st;
        for (auto &entry : mp) {
            reverse(entry.second.begin(), entry.second.end());
        }

        // Step 2: Process queries
        vector<int> ans;
        for (vector<int> &q : queries) {
            if (q[0] > q[1]) swap(q[0], q[1]);

            if (q[0] == q[1]) {
                ans.push_back(q[0]); 
                continue;
            }

            int idx = max(q[0], q[1]);
            int ele = max(heights[q[0]], heights[q[1]]);

            if (ele == heights[idx] && heights[idx] != heights[q[0]]) {
                ans.push_back(idx); 
                continue;
            }

            auto check = mp.upper_bound(idx);
            if (check == mp.begin()) {
                ans.push_back(-1); 
                continue;
            }

            check = prev(check);
            auto &nextTaller = check->second;

            auto ub = lower_bound(nextTaller.begin(), nextTaller.end(), make_pair(ele + 1, idx));
            if (ub == nextTaller.end()) {
                ans.push_back(-1);
            } else {
                ans.push_back(ub->second);
            }
        }

        return ans;
    }
};
