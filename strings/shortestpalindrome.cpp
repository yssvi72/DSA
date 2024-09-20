class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
      
        int end = n - 1;
        int i = 0;
        
        while (end >= 0) {
            if (s[i] == s[end]) {
                i++;
            }
            end--;
        }

      
        if (i == n) return s;

        
        string add = s.substr(i);
        reverse(add.begin(), add.end());
        
        
        return add + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};
