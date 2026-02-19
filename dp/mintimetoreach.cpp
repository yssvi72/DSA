class Solution {
    using pii = pair<int,pair<int,int>> ;
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<pii,vector<pii>,greater<pii>> pq ;
        vector<vector<int>> dist(moveTime.size(),vector<int>(moveTime[0].size(),INT_MAX)) ;
        dist[0][0] = 0 ;
        pq.push({0,{0,0}}) ;
        vector<vector<int>> dirs = {
            {0,1},
            {1,0},
            {-1,0},
            {0,-1}
        };
        while(!pq.empty()){
            auto [d,pos] = pq.top() ;
            pq.pop() ;
            if(d > dist[pos.first][pos.second]) continue ;
            for(auto &dir : dirs){
                int x = pos.first + dir[0] ;
                int y = pos.second + dir[1] ;
                if(x < 0 || y < 0 || x >= moveTime.size() || y >= moveTime[0].size()) continue ;
                if(dist[x][y] > max(d+1,moveTime[x][y]+1)){
                    dist[x][y] = max(d+1,moveTime[x][y]+1);
                    pq.push({dist[x][y],{x,y}}) ;
                }
            }
        }
        return dist[moveTime.size()-1][moveTime[0].size()-1] ;
    }
};
