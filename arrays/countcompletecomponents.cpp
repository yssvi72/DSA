class Solution {
public:
void dfs(int idx,map<int,vector<int>>&mp,vector<bool>&visited,int &v, int &e){
    visited[idx] = true;
    v++;
    e+=mp[idx].size();
    for(int &neighbour:mp[idx]){
        if(!visited[neighbour]){
            dfs(neighbour,mp,visited,v,e);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        map<int,vector<int>>mp;
        int ans =0;
        //graph creation
        for(auto &x:edges){
            int u = x[0];
            int v = x[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==true) continue;
            int v=0,e = 0;
            dfs(i,mp,visited,v,e);
              if (v * (v - 1) / 2 == e / 2) {
                ans++;
            }
        }
        return ans;
    }
};
