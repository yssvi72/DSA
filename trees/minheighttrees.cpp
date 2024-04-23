class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>>g;
    for(auto &e: edges) g[e[0]].insert(e[1]), g[e[1]].insert(e[0]);
    
    while(g.size() > 2){
      vector<pair<int,int>>v;
      for(auto &[x, st] : g)
        if(st.size() == 1) v.push_back({x, *st.begin()});
      while(!v.empty()){
        auto [x, y] = v.back(); v.pop_back();
        g.erase(x);
        g[y].erase(x);
      }
    }
    
    vector<int>ans;
    for(auto &[x, st]: g) ans.push_back(x);
    if(ans.empty()) ans.push_back(0);
    return ans;
    }
};
