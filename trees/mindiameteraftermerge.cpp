class Solution {
    pair<int, int> dfs(int node, int dist, bool *visited, vector<vector<int>> & tree){
        visited[node] = true;
        int dest = node, maxDist = dist;
        for(const int & child : tree[node]){
            if(visited[child]) continue;
                auto [tDest, tMaxDist] = dfs(child, dist+1, visited, tree);
                if(tMaxDist > maxDist){
                    dest = tDest;
                    maxDist = tMaxDist;
                }
            }
        visited[node] = false;
        return {dest, maxDist};
    }

    int diameter(const int n, vector<vector<int>> & tree){
        bool *visited = (bool *) calloc(n, sizeof(bool));

        auto [far1, dist1] = dfs(0, 0, visited, tree);
        auto [far2, dist2] = dfs(far1, 0, visited, tree);

        return dist2;
    }

    vector<vector<int>> to_tree(const int n, vector<vector<int>> & edges){
        vector<vector<int>> tree(n);

        for(const vector<int> & edge : edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        return tree;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        const int n = edges1.size() + 1;
        const int m = edges2.size() + 1;

        vector<vector<int>> tree1 = to_tree(n, edges1);
        vector<vector<int>> tree2 = to_tree(m, edges2);

        const int diameter1 = diameter(n, tree1);
        const int diameter2 = diameter(m, tree2);

        int minDiameter = max(diameter1, diameter2);
        
        int depth1 = ceil(diameter1 / 2.0);
        int depth2 = ceil(diameter2 / 2.0);

        return max(minDiameter, depth1 + depth2 + 1);
    }
};
