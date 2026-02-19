
  class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;  // To store word frequencies
        vector<string> result;

        // Process both sentences by splitting them into words and counting them
        addWordsToMap(s1, wordCount);
        addWordsToMap(s2, wordCount);

        // Collect words that appear exactly once
        for ( auto word : wordCount) {
            if (word.second == 1) {
                result.push_back(word.first);
            }
        }

        return result;
    }

private:
    // Helper function to split a string into words and update their count in the map
    void addWordsToMap( string sentence, unordered_map<string, int>& wordCount) {
        istringstream stream(sentence);
        string word;
        while (stream >> word) {
            wordCount[word]++;
        }
    }
};
    
