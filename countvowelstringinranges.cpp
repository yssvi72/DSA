class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int N = words.size(); // Number of words in the input array
        int Q = queries.size(); // Number of queries
        vector<int> result(Q); // Result array to store the answers to queries
        vector<int> cumSum(N); // Prefix sum array to track vowel string counts

        // Build the cumulative sum array
        int sum = 0;
        for (int i = 0; i < N; i++) {
            // Check if the current word starts and ends with a vowel
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                sum++;
            }
            cumSum[i] = sum; // Update the cumulative sum
        }

        // Process each query
        for (int i = 0; i < Q; i++) {
            int l = queries[i][0]; // Start index of the query
            int r = queries[i][1]; // End index of the query

            // Calculate the count of vowel strings in the range [l, r]
            result[i] = cumSum[r] - (l > 0 ? cumSum[l - 1] : 0);
        }

        return result; // Return the result array
    }
};
