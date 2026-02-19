class Solution {
    int timer = 1;
    void dfs(vector<vector<int>> &adj, vector<int> &high, vector<int> &low, int node, int par, vector<vector<int>>& ans) {
        if (high[node]) return;
        low[node] = high[node] = timer;
        timer++;
        
        for (auto it: adj[node]) {
            if (it == par) continue;
            dfs(adj, high, low, it, node, ans);
            low[node] = min(low[node], low[it]);
            if (low[it] > high[node]) {
                ans.push_back({it, node});
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> low(n);
        vector<int> high(n);
        vector<vector<int>> ans;
        dfs(adj, high, low, 0, -1, ans);
        return ans;
    }
};
