class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> arr ; 
        int flag = groups[0];
        arr.push_back(words[0]);
        for(int i = 1 ; i < groups.size() ; i++){
            
            if(groups[i] != flag){
                arr.push_back(words[i]);
                flag = groups[i];

            }
        }
        return arr;
    }
};
