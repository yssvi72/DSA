class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxCol = 0;
        bool trace[n][m];
        memset(trace, 0, n*m);
        queue<pair<int, int>> q; // x, y
        for(int i=0; i<n; ++i)
            q.push({i,0});
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if(y > maxCol)
                maxCol = y;
            if(maxCol == m-1) // early break
                break;
            int curVal = grid[x][y];
            // boardcast
            if(x > 0 && !trace[x-1][y+1] && grid[x-1][y+1] > curVal){
                q.push({x-1, y+1});
                trace[x-1][y+1] = true;
            }
            if(!trace[x][y+1] && grid[x][y+1] > curVal) {
                q.push({x, y+1});
                trace[x][y+1] = true;
            }
            if(x < n-1 && !trace[x+1][y+1] && grid[x+1][y+1] > curVal) {
                q.push({x+1, y+1});
                trace[x+1][y+1] = true;
            }
        }
        return maxCol;
    }
};
