/* You are given three strings s1, s2, and s3. You have to perform the following operation on these three strings as many times as you want.

In one operation you can choose one of these three strings such that its length is at least 2 and delete the rightmost character of it.

Return the minimum number of operations you need to perform to make the three strings equal if there is a way to make them equal, otherwise, return -1.
Input: s1 = "abc", s2 = "abb", s3 = "ab"
Output: 2
Explanation: Performing operations on s1 and s2 once will lead to three equal strings.
It can be shown that there is no way to make them equal with less than two operations.*/
class Solution {
public:
    int findMinimumOperations(string a, string b, string c) {
        if(a[0]!=b[0] || a[0]!=c[0] || c[0]!=b[0]) return -1;
        int p=a.size();
        int q=b.size();
        int r=c.size();
        int n=min({p,q,r}),i;
        for(i=0;i<n;i++){
            if(a[i]!=b[i] || c[i]!=b[i]) return p+q+r-(3*i);
        }
        return p+q+r-(3*i);
    }
};
