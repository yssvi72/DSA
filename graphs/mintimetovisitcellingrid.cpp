class comparator{
    public:
    bool operator()(vector<int>& a,vector<int>& b){
        return a[0]>b[0];
    }
};

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(min(grid[0][1],grid[1][0])>1)return -1;
        priority_queue<vector<int>,vector<vector<int>>,comparator>pq;
        pq.push({0,0,0});
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,INT_MAX));
        while(!pq.empty()){
            int val=pq.top()[0];
            int i=pq.top()[1];
            int j=pq.top()[2];
            pq.pop();
            if(vis[i][j]!=INT_MAX)continue;
            // cout<<i<<" "<<j<<" "<<val<<endl;
            if(i==m-1 && j==n-1)return val;
            vis[i][j]=val;
            if(i-1>=0){
                // cout<<"t ";
                if(grid[i-1][j]<=val+1)pq.push({val+1,i-1,j});
                else{
                    int temp=grid[i-1][j]-val-1;
                    if(temp%2)temp++;
                    pq.push({temp+val+1,i-1,j});
                }
            }
            if(j-1>=0){
                // cout<<"l ";
                if(grid[i][j-1]<=val+1)pq.push({val+1,i,j-1});
                else{
                    int temp=grid[i][j-1]-val-1;
                    if(temp%2)temp++;
                    pq.push({temp+val+1,i,j-1});
                }
            }
            if(i+1<m){
                // cout<<"d ";
                if(grid[i+1][j]<=val+1)pq.push({val+1,i+1,j});
                else{
                    int temp=grid[i+1][j]-val-1;
                    if(temp%2)temp++;
                    pq.push({temp+val+1,i+1,j});
                }
            }
            if(j+1<n){
                // cout<<"r "<<grid[i][j+1]<<" "<<val+1;
                if(grid[i][j+1]<=val+1)pq.push({val+1,i,j+1});
                else{
                    int temp=grid[i][j+1]-val-1;
                    if(temp%2)temp++;
                    pq.push({temp+val+1,i,j+1});
                }
            }
            // cout<<endl;
        }
        return -1;
    }
};
