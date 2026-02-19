class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
         unordered_map<string,int>mp;
         for(auto i:matrix){
            string s="";
            int first=i[0];
            for(int j=0;j<i.size();j++){
                 if(i[j]==first){
                    s+='s';
                 }
                 else{
                    s+='b';
                 }
            }
            mp[s]++;
         }
         int ans=0;
         for(auto i:mp){
          ans=max(ans,i.second);
         }
         return ans;

    }
};
