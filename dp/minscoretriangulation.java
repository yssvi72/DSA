class Solution {
    int[] values;
    int n;
    int[][] dp;

    public int minScoreTriangulation(int[] values) {
        this.values = values;
        n = values.length;
        
        // dp[i][j] stores minimum score for range i...j
        dp = new int[n][n];
        for(int[] row : dp){
            Arrays.fill(row, -1); // -1 means not calculated yet
        }

        return scoreTriangulation(0, n - 1); // solve for full polygon
    }

    private int scoreTriangulation(int i, int j){
        // Base case: no space to form triangle
        if(i + 1 == j) return 0;

        // If already calculated, return stored result
        if(dp[i][j] != -1) return dp[i][j];
        
        int minScore = Integer.MAX_VALUE;

        // Try every possible third vertex k between i and j
        for(int k = i + 1; k < j; k++){
            int score = scoreTriangulation(i, k)  // left side
                      + values[i] * values[j] * values[k] // current triangle
                      + scoreTriangulation(k, j); // right side

            minScore = Math.min(minScore, score);
        }

        return dp[i][j] = minScore; // store and return
    }
}
