class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back(i);
            graph[edges[i][1]].push_back(i);
        }
        vector<int> sourceDis(n, 1e9), desDis(n, 1e9);
        sourceDis[source] = desDis[destination] = 0;
        dijktra(graph, edges, desDis, sourceDis, destination, target);
        dijktra(graph, edges, sourceDis, desDis, source, target);
        if(sourceDis[destination] != target) return {};
        for(auto &edge : edges) edge[2] = max(1, edge[2]);
        return edges;
    }
    void dijktra(vector<vector<int>>& graph, vector<vector<int>>& edges, vector<int>& sDis, vector<int>& dDis, int source, int target) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, source});
        while(!q.empty()) {
            auto [cost, u] = q.top();
            q.pop();
            if(cost > sDis[u]) continue;
            for(int i : graph[u]) {
                int v = (edges[i][0]==u?edges[i][1]:edges[i][0]);
                if(edges[i][2] == -1) edges[i][2] = max(edges[i][2], target-sDis[u]-dDis[v]);
                int w = max(1, edges[i][2]);
                if(cost+w < sDis[v]) 
                    q.push({sDis[v] = cost+w, v});
            }
        }
    }
};
