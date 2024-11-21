
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 3;
        }
        for (const auto& guard : guards) {
            int row = guard[0];
            int col = guard[1];
            for (int j = col + 1; j < n; ++j) {
                if (grid[row][j] == 2 || grid[row][j] == 3) break;
                grid[row][j] = 1;
            }
            for (int j = col - 1; j >= 0; --j) {
                if (grid[row][j] == 2 || grid[row][j] == 3) break;
                grid[row][j] = 1;
            }
            for (int i = row + 1; i < m; ++i) {
                if (grid[i][col] == 2 || grid[i][col] == 3) break;
                grid[i][col] = 1;
            }
            for (int i = row - 1; i >= 0; --i) {
                if (grid[i][col] == 2 || grid[i][col] == 3) break;
                grid[i][col] = 1;
            }
        }
        int cnt = 0;
        for (const auto& row : grid) {
            for (int cell : row) {
                if (cell == 0) ++cnt;
            }
        }
        return cnt;
    }


};
