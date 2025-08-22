class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        //i1 and i2 will store the first and last row
        //j1 and j2 will store the first and last column
        int n = grid.size(), m = grid[0].size(), i1 = n, i2 = 0, j1 = m, j2 = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j]) {
                    i1 = min(i1, i);
                    i2 = max(i2, i);
                    j1 = min(j1, j);
                    j2 = max(j2, j);
                }
            }
        }

        return (i2-i1+1)*(j2-j1+1);
    }
};
