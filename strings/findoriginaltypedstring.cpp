class Solution:
    def possibleStringCount(self, word: str) -> int:
        count = 1
        if len(set(word)) == 1:
            return len(word)
        for i in range(len(word) - 1):
            if word[i] == word[i+1]:
                count += 1
        return count
