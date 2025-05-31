class Solution {
    int check(vector<int> & edges, int node2, vector<int> & distNode1, int mid){
        int dist = 0, ans = -1;
        int n = edges.size();
        vector<bool> vis(n, false);
        while(node2 != -1 && !vis[node2]){
            vis[node2] = true;
            if(distNode1[node2] != -1){
                int maxDist = max(distNode1[node2], dist);
                if(maxDist <= mid){
                    if(ans == -1 || node2 < ans) ans = node2;
                }
            }
            node2 = edges[node2];
            dist++;
        }
        return ans;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int low = 0, high = n - 1, ans = -1, dist = 0;

        vector<int> distNode1(n, -1);
        while(node1 != -1 && distNode1[node1] == -1){
            distNode1[node1] = dist++;
            node1 = edges[node1];
        }

        while(low <= high){
            int mid = low + (high - low) / 2;
            int node = check(edges, node2, distNode1, mid);
            if(node != -1){
                ans = node;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};
