class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        map<int,vector<int>> adj;
        int n = graph.size();
        vector<int> outgoing(n,0);
        for(int i = 0;i<graph.size();i++){
            int cnt = 0;
            for(int j = 0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                cnt++;
            }
            outgoing[i] = cnt;
        }

        queue<int> q;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(outgoing[i] == 0){
                q.push(i);               
            }
        }

        while(!q.empty()){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            for(auto val : adj[curr]){
                outgoing[val]--;
                if(outgoing[val] == 0){
                    q.push(val);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
