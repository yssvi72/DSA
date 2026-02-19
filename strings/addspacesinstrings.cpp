class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int start = 0,i=0;
        int n = s.length();
        string ans="";
        while(i<n){
            if(start<spaces.size() && spaces[start]==i){
                ans+=" ";
                start++;
            }
            ans+=s[i];
            i++;
        }
        return ans;
    }
};
