//Given a string, we have to find out all its subsequences of it. 
//A String is a subsequence of a given String, that is generated by deleting some character of a given string without changing its order.
//Input : “abc”
/*Output : 
a  
b 
a b 
c 
a c 
b c 
a b c 
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
      int j = 0; // For index of str1 (or subsequence
 
    // Traverse str2 and str1, and
    // compare current character
    // of str2 with first unmatched char
    // of str1, if matched
    // then move ahead in str1
    for (int i = 0; i < t.length() && j < s.length(); i++)
        if (s[j] == t[i])
            j++;
 
    // If all characters of str1 were found in str2
    return (j == s.length());  
    }
};
