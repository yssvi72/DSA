class Solution {
public:
    int n, m;
    int fn(vector<vector<int>>& a, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == 0)  return 0;
        int ans = a[i][j]; 
        a[i][j]=0;
        ans += fn(a, i + 1, j);
        ans += fn(a, i - 1, j);
        ans += fn(a, i, j + 1);
        ans += fn(a, i, j - 1);
        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0; 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                    ans = max(ans, fn(grid, i, j));
                
        return ans;
    }
};
