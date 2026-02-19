class Solution {
private:
    void updateDistance(vector<vector<int>>& graph, int current, vector<int>& distance){
        int newDist = distance[current] + 1;

        for(int neighbor : graph[current]){
            if(distance[neighbor] <= newDist) continue;
            distance[neighbor] = newDist;
            updateDistance(graph, neighbor, distance);
        }
    }   
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> distance(n);
        vector<vector<int>> graph(n);
        vector<int> ans;

        for(int i = 0; i < n; i++){
            distance[i] = n - i - 1;
        }

        for(int i = 0; i < n-1; i++){
            graph[i+1].push_back(i);
        }

        for(int i = 0; i < queries.size(); i++){
            int source = queries[i][0];
            int target = queries[i][1];

            graph[target].push_back(source);
            distance[source] = min(distance[source], distance[target]+1);
            updateDistance(graph, source, distance);

            ans.push_back(distance[0]);
        }

        return ans;
    }
};
