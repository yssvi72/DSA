class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = (int)isWater.size();
        int m = (int)isWater[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        vector<int> dirRow = {1, 0, -1, 0};
        vector<int> dirCol = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + dirRow[i], ncol = col + dirCol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol]) {
                    ans[nrow][ncol] = 1 + ans[row][col];
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return ans;
    }
};
