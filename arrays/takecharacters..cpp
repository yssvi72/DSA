class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        unordered_map<char,int>freq;
        int res=INT_MAX;
        int maxLen=INT_MIN;
        int i=0,j=0;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        if(freq['a']<k||freq['b']<k||freq['c']<k)return -1;
        while(j<n){
            freq[s[j]]--;

            while(i<=j&&freq['a']<k||freq['b']<k||freq['c']<k){
                freq[s[i]]++;
                i++;
            }

            if(freq['a']>=k&&freq['b']>=k&&freq['c']>=k){
                maxLen=max(maxLen,j-i+1);
            }

            j++;
        }

        return n-maxLen;
    }
};
