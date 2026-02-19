class Solution {
public:
    // Generates the nth term of the Count and Say sequence.
    string countAndSay(int n) {
        // Start with the first term: "1"
        string s = "1";
        // Iterate n-1 times to build the sequence up to the nth term.
        for (int i = 1; i < n; ++i) {
            processTerm(s); // Generate the next term from the current term.
        }
        return s;
    }
    
private:
    // Helper function to process the current term and generate the next term.
    void processTerm(string &s) {
        string nextTerm = "";
        int count = 0;
        char currentChar = s[0];
        
        // Traverse the current term character by character.
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == currentChar) {
                // If the digit matches the current character, increment the count.
                ++count;
            } else {
                // On encountering a new digit, append the count and the current digit.
                nextTerm += to_string(count) + currentChar;
                // Update the current character and reset the count.
                currentChar = s[i];
                count = 1;
            }
        }
        // Append the count and digit for the last sequence.
        nextTerm += to_string(count) + currentChar;
        // Update the original string to the next term.
        s = nextTerm;
    }
};
