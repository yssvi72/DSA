class Solution {
public:

    // Function to color a tree using 2 colors (bipartite coloring)
    // Returns: (map of node->color, count of nodes with color 0)
    pair<unordered_map<int, bool>, int> reachable(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;
        unordered_map<int, bool> colors;
        queue<tuple<int, int, int>> q;
        int zeroColor = 1; // Initial node gets color 0

        // Build adjacency list
        for(auto e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        q.push({0, -1, 0}); // Start BFS from node 0
        colors[0] = 0;

        while(!q.empty()) {
            auto [node, parent, color] = q.front();
            q.pop();

            for(auto v: g[node]) {
                if(v != parent) {
                    q.push({v, node, !color});
                    colors[v] = !color;
                    if(!color) {
                        zeroColor++; // Count how many nodes are colored 0
                    }
                }
            }
        }

        return make_pair(colors, zeroColor);
    }

    // Main function to compute max target nodes
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // Get color map and zeroColor count for both trees
        pair<unordered_map<int, bool>, int> points_1 = reachable(edges1);
        pair<unordered_map<int, bool>, int> points_2 = reachable(edges2);

        // Get the size of the larger color group in second tree
        int maxColorFromSecondEdge = max(
            points_2.second, // nodes with color 0
            (int)points_2.first.size() - points_2.second // nodes with color 1
        );

        vector<int> ans(points_1.first.size(), 0);

        int nodeOneZeroColor = points_1.second;
        int nodeOneOneColor = (int)points_1.first.size() - points_1.second;

        // For each node in first tree, calculate maximum pairings
        for(auto [node, color]: points_1.first) {
            if(color) {
                // Node is color 1, so pair with 0-colored nodes from Tree 2
                ans[node] = nodeOneOneColor + maxColorFromSecondEdge;
            } else {
                // Node is color 0, so pair with 1-colored nodes from Tree 2
                ans[node] = nodeOneZeroColor + maxColorFromSecondEdge;
            }
        }
        return ans;
    }
};
