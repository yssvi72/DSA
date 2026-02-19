class Solution {
    // Helper function to check if a character is a vowel.
    bool isVowel(char c) {
        static const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        return vowels.count(c);
    }

    // Helper function to count substrings with at least 'k' consonants.
    long atLeastK(const string& word, int k) {
        long validSubstringCount = 0;
        int start = 0, end = 0;
        unordered_map<char, int> vowelCount;
        int consonantCount = 0;

        while (end < word.length()) {
            char newLetter = word[end];

            // Update counts
            if (isVowel(newLetter)) {
                vowelCount[newLetter]++;
            } else {
                consonantCount++;
            }

            // Shrink window while condition is met
            while (vowelCount.size() == 5 && consonantCount >= k) {
                validSubstringCount += word.length() - end;
                char startLetter = word[start++];
                
                if (isVowel(startLetter)) {
                    if (--vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }
            }
            end++;
        }

        return validSubstringCount;
    }

public:
    long countOfSubstrings(const string& word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};
