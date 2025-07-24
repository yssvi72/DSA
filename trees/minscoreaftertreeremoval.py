class Solution {
public:
        int totalXor;
    vector<vector<int>> tree;
    vector<int> xorSubtree, parent;

    int dfs(int node, int par, vector<int>& nums) {
        int currXor = nums[node];
        parent[node] = par;
        for (int nei : tree[node]) {
            if (nei != par) {
                currXor ^= dfs(nei, node, nums);
            }
        }
        xorSubtree[node] = currXor;
        return currXor;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
         int n = nums.size();
        tree.resize(n);
        xorSubtree.resize(n);
        parent.resize(n);

        // Build the tree
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // DFS to compute subtree XOR and parent
        totalXor = dfs(0, -1, nums);

        int ans = INT_MAX;

        // Try all pairs of edges
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = i, b = j;

                // Check if one is ancestor of the other
                if (isAncestor(a, b)) {
                    // a is ancestor of b
                    int x = xorSubtree[b];
                    int y = xorSubtree[a] ^ xorSubtree[b];
                    int z = totalXor ^ xorSubtree[a];
                    ans = min(ans, score(x, y, z));
                } else if (isAncestor(b, a)) {
                    // b is ancestor of a
                    int x = xorSubtree[a];
                    int y = xorSubtree[b] ^ xorSubtree[a];
                    int z = totalXor ^ xorSubtree[b];
                    ans = min(ans, score(x, y, z));
                } else {
                    // Independent subtrees
                    int x = xorSubtree[a];
                    int y = xorSubtree[b];
                    int z = totalXor ^ xorSubtree[a] ^ xorSubtree[b];
                    ans = min(ans, score(x, y, z));
                }
            }
        }
        return ans;
    }

      bool isAncestor(int u, int v) {
        while (v != -1) {
            if (u == v) return true;
            v = parent[v];
        }
        return false;
    }

    int score(int a, int b, int c) {
        int mx = max({a, b, c});
        int mn = min({a, b, c});
        return mx - mn;
    }
};
