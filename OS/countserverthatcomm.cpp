class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns
        
        int total = 0; // To count total servers that communicate
        vector<int> rows(n, 0), cols(m, 0); // Frequency arrays for rows and columns
        
        // Step 1: Count the total servers and track row & column frequencies
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) { // If there is a server at (i, j)
                    ++total;    // Increment total server count
                    ++rows[i];  // Increment row frequency
                    ++cols[j];  // Increment column frequency
                }
            }
        }
        
        // Step 2: Subtract isolated servers
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Check if this server is isolated
                if (grid[i][j] && rows[i] == 1 && cols[j] == 1) {
                    --total; // Reduce count of servers since it cannot communicate
                }
            }
        }
        
        return total; // Return the final count of communicating servers
    }
};class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns
        
        int total = 0; // To count total servers that communicate
        vector<int> rows(n, 0), cols(m, 0); // Frequency arrays for rows and columns
        
        // Step 1: Count the total servers and track row & column frequencies
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) { // If there is a server at (i, j)
                    ++total;    // Increment total server count
                    ++rows[i];  // Increment row frequency
                    ++cols[j];  // Increment column frequency
                }
            }
        }
        
        // Step 2: Subtract isolated servers
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Check if this server is isolated
                if (grid[i][j] && rows[i] == 1 && cols[j] == 1) {
                    --total; // Reduce count of servers since it cannot communicate
                }
            }
        }
        
        return total; // Return the final count of communicating servers
    }
};
