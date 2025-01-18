class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>cost(n,vector<int>(m,INT_MAX));

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>>minheap;

        cost[0][0]=0;
        minheap.push({0,{0,0}});

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while(!minheap.empty()){
            auto t = minheap.top();
            minheap.pop();
            int currcost = t.first;
            int x = t.second.first;
            int y = t.second.second;

            if (currcost > cost[x][y]) continue;

            for(int i=0 ; i<4 ; i++){
                int newx = x+dx[i];
                int newy = y+dy[i];

                if(newx<n && newy<m && newx>=0 && newy>=0){
                    // main Logic
                    int newcost = currcost + ((grid[x][y]==i+1) ? 0 : 1);
                    if(newcost<cost[newx][newy]){
                        minheap.push({newcost,{newx,newy}});
                        cost[newx][newy]=newcost;
                    }
                }
            }
        }
        return cost[n-1][m-1];
    }
};
