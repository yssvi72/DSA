class Solution {
private:
    int N,M;
    vector<vector<int>> visit;
    vector<vector<int>> GRID;
    vector<int> cor = {1, 0, -1, 0, 1};
public:
    int dfs(int i, int j){
        if(visit[i][j]) return 0;
        visit[i][j] = 1;
        int fishesCaught = GRID[i][j];

        for(int k = 0; k < 4; k++){
            int a = i + cor[k];
            int b = j + cor[k+1];

            if(a == N || b == M || a < 0 || b < 0 || GRID[a][b] == 0 || visit[a][b] == 1)
                continue;
            fishesCaught += dfs(a, b);
        }
        return fishesCaught;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        GRID = grid;
        N = n, M = m;
        visit = vector<vector<int>>(n, vector<int>(m,0));
        int maxFish = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] and !visit[i][j]){
                    maxFish = max(maxFish, dfs(i,j));
                }
            }
        }

        return maxFish;
    }
};
