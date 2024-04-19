
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      if (0 == grid.size() || 0 == grid[0].size())
            return 0;

        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if ('1' == grid[i][j]) {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        return numIslands;
    }
    
private:
    void dfs(vector<vector<char> >& grid, int i, int j)
    {
        if (0 > i || i >= grid.size() || 0 > j || j >= grid[0].size() || '0' == grid[i][j])
            return;

        grid[i][j] = '0'; // mark the value to avoid duplication
        vector<int> dir({-1, 0, 1, 0, -1}); // c++11/14
        // int nums[] = {-1, 0, 1, 0, -1};
        // vector<int> dir(nums, nums + sizeof(nums) / sizeof(int));
        for (int idx = 0; idx < dir.size() - 1; idx++) {
            int rowIdx = i + dir[idx]; // row index
            int colIdx = j + dir[idx + 1]; // col index
            dfs(grid, rowIdx, colIdx);
        }
  
    }
};
