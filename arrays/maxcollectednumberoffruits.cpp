class Solution {
private:
    int n;
    
    // row = i, col = j
    int dfs3(int row, int col, vector<vector<int>>& mat) {
        if (row < 0 || col < 0 || row >= n || col >= n) return 0;
        
        int val = mat[row][col];
        int res = 0;

        if (row == col) {
            res = max(res, dfs3(row + 1, col + 1, mat));
        }
        else if (row - 1 == col) {
            res = max({res,
                       dfs3(row + 1, col + 1, mat),
                       dfs3(row, col + 1, mat)});
        }
        else {
            res = max({res,
                       dfs3(row + 1, col + 1, mat),
                       dfs3(row, col + 1, mat),
                       dfs3(row - 1, col + 1, mat)});
        }
        
        return val + res;
    }

    int dfs2(int row, int col, vector<vector<int>>& mat) {
        if (row < 0 || col < 0 || row >= n || col >= n) return 0;
        
        int val = mat[row][col];
        int res = 0;

        if (row == col) {
            res = max(res, dfs2(row + 1, col + 1, mat));
        }
        else if (row == col - 1) {
            res = max({res,
                       dfs2(row + 1, col + 1, mat),
                       dfs2(row + 1, col, mat)});
        }
        else {
            res = max({res,
                       dfs2(row + 1, col + 1, mat),
                       dfs2(row + 1, col, mat),
                       dfs2(row + 1, col - 1, mat)});
        }
        
        return val + res;
    }

public:
    int maxCollectedFruits(vector<vector<int>>& mat) {
        n = mat.size();
        int total = 0;

        // child - 1
        // he will eat all diagonal fruits, so set them to 0 
        for (int i = 0; i < n; i++) {
            total += mat[i][i];
            mat[i][i] = 0;
        }
        
        // child - 2
        total += dfs3(n - 1, 0, mat);
        // child - 3
        total += dfs2(0, n - 1, mat);

        return total;
    }
};
