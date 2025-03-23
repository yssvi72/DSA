class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        // Step 1 : Create a Graph

        vector<pair<int, int>> adj[n];
        for (auto x : roads) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }

        // Step 2 : Initialization

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            q; // {distance,node}
        vector<int> ways(n, 0);
        vector<long long> distance(n, 1e18);
        int mod = int(1e9 + 7);

        distance[0] = 0;
        ways[0] = 1;
        q.push({0, 0}); // {distance=0 , node=0}

        // Step 3 : Intution
        // ways to reach a node A = ways to rech node that leads to node A

        while (!q.empty()) {
            int node = q.top().second;
            long long dst = q.top().first;
            q.pop();

            for (auto x : adj[node]) {
                int adjnode = x.first; // as stored in graph in form of pair
                                       // {node,distance}
                int edgewt = x.second;

                // if we are coming to the node for the first time
                if (dst + edgewt < distance[adjnode]) {
                    distance[adjnode] = dst + edgewt;
                    q.push({dst + edgewt, adjnode});
                    ways[adjnode] = ways[node];
                }

                // if we are coming to the node back with similar minimum
                // distance
                else if (dst + edgewt == distance[adjnode]) {

                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};

// Similar questions can be solved by Dijkstra method:
// 743. Network Delay Time
// 2290. Minimum Obstacle Removal to Reach Corner
// 787. Cheapest Flights Within K Stops
// 1514. Path with Maximum Probability
// 2045. Second Minimum Time to Reach Destination
// 1334. Find the City With the Smallest Number of Neighbors at a Threshold
// Distance 1631. Path With Minimum Effort 778. Swim in Rising Water

// Practice them in a row for your better understanding! Good Luck and have
// fun!\U0001f91e\U0001f914 \U0001f600
