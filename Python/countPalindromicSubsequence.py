class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        # Initialize a set to store unique palindromic subsequences
        unique_palindromes = set()
        
        # Iterate through all lowercase English letters
        for char in range(26):
            current_char = chr(ord('a') + char)  # Convert number to character
            left = s.find(current_char)  # Find the first occurrence
            right = s.rfind(current_char)  # Find the last occurrence
            
            # Ensure there is a valid range for a palindrome
            if left != -1 and right - left > 1:
                # Add all unique middle characters to the set
                middle_chars = set(s[left + 1:right])
                for mid in middle_chars:
                    unique_palindromes.add((current_char, mid, current_char))
        
        # Return the count of unique palindromic subsequences
        return len(unique_palindromes)
